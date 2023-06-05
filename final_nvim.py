from pynvim import attach
import subprocess

import json 

def run_c_program(cmd, num, proc):
    input_str = f"{cmd}{num}"
    proc.stdin.write(input_str)
    proc.stdin.flush()

    output = proc.stdout.readline()
    print(output.strip())
    return output.strip()



def get_c_list(cmd, proc):
    input_str = f"{cmd}"
    proc.stdin.write(input_str)
    proc.stdin.flush()

    out = []
    output = proc.stdout.readline()
    while("EOF" not in output):
        out.append(output.strip())
        print(output.strip())
        output = proc.stdout.readline()
    out.append(output.strip())
    return out

nvim = attach('socket', path='/tmp/nvim')

last_changedtick = None
processed_lines = dict()

yanked = ''
deleted = ''



current_buffer = nvim.current.buffer
changed_lines = current_buffer.api.get_lines(0, -1, True)

for line, data in enumerate(changed_lines):
    if line not in processed_lines:
        processed_lines[line] = data
        continue
    if processed_lines[line] != data:
        processed_lines[line] = data


buffersk = dict()
BufCount = 0
nvim.subscribe('yanked')
nvim.subscribe('open_version')
nvim.subscribe('show_clipboard')
nvim.subscribe('saved')
nvim.subscribe('save_file_version')
nvim.subscribe('addedline')
nvim.subscribe('rmedline')
nvim.subscribe('intobuffer')
nvim.subscribe('concatclip')
nvim.subscribe('show_version_history')
yanked_lines = []

cmd = """highlight CustomError ctermfg=red guifg=red"""
nvim.command(cmd)
cmd = "sign define error numhl=CustomError"
nvim.command(cmd)


cmd = """highlight CustomAdd ctermfg=green guifg=green"""
nvim.command(cmd)
cmd = "sign define addline numhl=CustomAdd"
nvim.command(cmd)

cmd = """highlight CustomMod ctermfg=yellow guifg=yellow"""
nvim.command(cmd)
cmd = "sign define modded numhl=CustomMod"
nvim.command(cmd)


proc = subprocess.Popen(['./a.out'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)
while True:
    sd = nvim.next_message()
    print(sd)

    if sd[1] == "show_clipboard":
        print(sd)
        cmd = "1\n4\n"
        y = get_c_list(cmd, proc)
        cds = "{"+json.dumps(y)[1:-1]+"}"
        a = """local actions = require "telescope.actions"
            local action_state = require "telescope.actions.state"

            local pickers = require "telescope.pickers"
            local finders = require "telescope.finders"
            local sorters = require "telescope.sorters"
            
            function enter(prompt_buffer)
                local selected = action_state.get_selected_entry()
                local cmd = "call rpcnotify(0,'intobuffer','"..selected[1] .."')"
                vim.cmd(cmd)
                local cmd1 = 'let @"="'..selected[1]..'"'
                vim.cmd(cmd1)
                actions.close(prompt_buffer)
            end

            local opts = { layout_strategy = "vertical", finder = finders.new_table"""+cds+""", sorter = sorters.get_generic_fuzzy_sorter({}), attach_mappings = function(prompt_buffer, map)
                map("i", "<CR>", enter)
                map("n", "<CR>", enter)
                return true 
            end,
            }
            local lel = pickers.new(opts)
            lel:find()"""
        nvim.command("lua "+a)
        

    if sd[1] == "open_version":
        nvim.command('let g:execute_buffer_length_check = 0')
        buffer = nvim.current.buffer
        ver = sd[2][0][-1]
        buf_id = sd[2][-1]
        cmd = "0\n6\n"+str(buf_id)+"\n"+str(ver)+"\n"
        y = get_c_list(cmd, proc)
        y = [item[2:] if item not in ['\ EMPTY', '\ EOX', '\ EOF', 'EOF'] else ' ' for item in y]
        for i in y:
            print(repr(i))
        buffer[:] = y
        nvim.command('let g:execute_buffer_length_check = 1')

    if sd[1] == "show_version_history":
        if sd[2][0] not in buffersk:
            buffersk[sd[2][0]] = BufCount
            BufCount+=1

        buf_id = buffersk[sd[2][0]]
        cmd = "0\n7\n"+str(buf_id)+"\n"
        s = get_c_list(cmd, proc)
        count = s.count("EOX")
        print("THIS MUCH EOX", count)
        y = []

        for i in range(count):
            y.append("Version History "+str(i+1))
        
        cds = "{"+json.dumps(y)[1:-1]+"}"
        a = """local actions = require "telescope.actions"
            local action_state = require "telescope.actions.state"
            local pickers = require "telescope.pickers"
            local finders = require "telescope.finders"
            local sorters = require "telescope.sorters"
            
            function enter(prompt_buffer)
                local selected = action_state.get_selected_entry()
                local cmd = 'call rpcnotify(0,"open_version","'..selected[1] ..'", """ + str(buf_id)+""")'

                vim.cmd(cmd)
                actions.close(prompt_buffer)
            end

            local opts = { layout_strategy = "vertical", finder = finders.new_table"""+cds+""", sorter = sorters.get_generic_fuzzy_sorter({}), attach_mappings = function(prompt_buffer, map)
                map("i", "<CR>", enter)
                map("n", "<CR>", enter)
                return true 
            end,
            }
            local lel = pickers.new(opts)
            lel:find()"""
        nvim.command("lua "+a)

    if sd[1] == "save_file_version":
        buffer = nvim.current.buffer 
        changed_lines = current_buffer.api.get_lines(0, -1, True)

        if sd[2][0] not in buffersk:
            buffersk[sd[2][0]] = BufCount
            BufCount+=1
        buf_id = buffersk[sd[2][0]]
        for i, j in enumerate(changed_lines):
            if j.strip() == "":
                j = "EMPTY"
            cmd = "0\n1\n"+str(buf_id)+"\n"+str(i)+"\n\ "+repr(j)[1:-1]+"\n"
            print(cmd)

            s = run_c_program(cmd, "", proc)
            if s == "Added":
                a = f"sign place 1 name=addline line={i+1}"
                nvim.command(a)
            if s == "Modified":
                a = f"sign place 1 name=modded line={i+1}"
                nvim.command(a)
                

        cmd = "0\n2\n"+str(buf_id)+"\n"
        s = get_c_list(cmd, proc)
        print(s)

        cmd = "0\n5\n"+str(buf_id)+"\n"
        run_c_program(cmd, "", proc)


    if sd[1] == "rmedline":

        c = sd[2][0]
        a = f"sign place 1 name=error line={c}"
        if sd[2][-1] not in buffersk:
            buffersk[sd[2][-1]] = BufCount
            BufCount+=1
        buf_id = buffersk[sd[2][-1]]
        cmd = "0\n4\n"+str(buf_id)+"\n"+str(sd[2][0])+"\n"
        run_c_program(cmd, "", proc)
        nvim.command(a)


    if sd[1] == "addedline":
        print(sd)
        c = sd[2][0]
        a = f"sign place 1 name=addline line={c}"
        if sd[2][-1] not in buffersk:
            buffersk[sd[2][-1]] = BufCount
            BufCount+=1
        buf_id = buffersk[sd[2][-1]]
        cmd = "0\n3\n"+str(buf_id)+"\n"+str(sd[2][0])+"\n"
        run_c_program(cmd, "", proc)
        nvim.command(a)
        print(sd)

    if sd[1] == "concatclip":
        c = "1\n3"
        a = eval('"'+run_c_program(c, "\n", proc)+'"')
        nvim.command(f'let @"="{a}"')
        print(a)

    if sd[1] == "yanked":
        yanked_string = nvim.eval('@\"')
        command = "1\n1\n" 
        number = repr(sd[2][-1])[1:-1]+"\n"
        y = run_c_program(command, number, proc)
        print("THIS GOT YANKED:", y)
        yanked = yanked_string
        deleted = ''  # Reset the deleted content
        

    if sd[1] == 'saved':
        buffer = nvim.current.buffer 
        changed_lines = current_buffer.api.get_lines(0, -1, True)

        if sd[2][0] not in buffersk:
            buffersk[sd[2][0]] = BufCount
            BufCount+=1
        buf_id = buffersk[sd[2][0]]
        for i, j in enumerate(changed_lines):
            if j.strip() == "":
                j = "EMPTY"
            cmd = "0\n1\n"+str(buf_id)+"\n"+str(i)+"\n\ "+repr(j)[1:-1]+"\n"
            s = run_c_program(cmd, "", proc)
            if s == "Added":
                a = f"sign place 1 name=addline line={i+1}"
                nvim.command(a)
            if s == "Modified":
                a = f"sign place 1 name=modded line={i+1}"
                nvim.command(a)

        cmd = "0\n2\n"+str(buf_id)+"\n"
        s = get_c_list(cmd, proc)
        print(s)


    nvim.command('sleep 10m')

'''

proc.stdin.close()
proc.wait()



        cds = "{"+json.dumps(y)[1:-1]+"}"
        a = """local actions = require "telescope.actions"
            local action_state = require "telescope.actions.state"
            local pickers = require "telescope.pickers"
            local finders = require "telescope.finders"
            local sorters = require "telescope.sorters"
            
            function enter(prompt_buffer)
                local selected = action_state.get_selected_entry()
                local cmd = "call rpcnotify(0,'intobuffer','"..selected[1] .."')"
                vim.cmd(cmd)
                local cmd1 = 'let @"="'..selected[1]..'"'
                vim.cmd(cmd1)
                actions.close(prompt_buffer)
            end

            local opts = { layout_strategy = "vertical", finder = finders.new_table"""+cds+""", sorter = sorters.get_generic_fuzzy_sorter({}), attach_mappings = function(prompt_buffer, map)
                map("i", "<CR>", enter)
                map("n", "<CR>", enter)
                return true 
            end,
            }
            local lel = pickers.new(opts)
            lel:find()"""
        nvim.command("lua "+a)


'''
