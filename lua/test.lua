-- str = string.rep("hello ", 100)
-- print("str: ", str)

-- testTable = {
    -- [".gif"] = true
-- }

-- str = nil
-- if testTable[".gif"] then
    -- print("yes")
-- else
    -- print("no")
-- end

-- local i = 0
-- repeat
    -- print("hello")
    -- i = i + 1
-- until i == 10

local string = string
local string_format = string.format
ngx_var = {
    [ "arg_appkey" ] = "3",
    -- [ "arg_act" ] = "webtest"
}

local function get_meeted_condition_unit(condition_group)
    local URI_ARG_PATTERN = "arg_%s"
    local uri_args = {}
    for _, condition_unit in ipairs(condition_group) do 

        local meet_condition_unit = true
        for _, condition_item in ipairs(condition_unit) do
            
            local field_name = condition_item.field_name  -- appkey/act
            
            local arg_name = string_format(URI_ARG_PATTERN, field_name)  -- arg_appkey/arg_act
            
            local arg_val = uri_args[field_name] or ngx_var[arg_name]  -- 1/2/3/webtest
            print("arg_val:", arg_val)
            if not arg_val then  -- 没有该uri arg, 不过滤
                print("--------1")
                meet_condition_unit = false
                break
            end

            if not uri_args[field_name] then
                print("--------2")
                uri_args[field_name] = arg_val  -- uri_args["arg_appkey"] = 1
            end

            local is_allow = true
            for _, filter_val in ipairs(condition_item.field_val) do
                print("filter_val: ", filter_val)
                if filter_val == arg_val then
                    print("--------3")
                    is_allow = false
                    break
                end
            end

            if is_allow then
                print("--------4")
                meet_condition_unit = false
                break
            end

        end

        if meet_condition_unit then
            print("--------5")
            return condition_unit
        end
    end

end

cgif_filter = {
    {
        {field_name = "appkey", field_val = {"1", "2"}},
        {field_name = "act", field_val = {"webtest"}},
    },

    {
        {field_name = "appkey", field_val = {"3"}},
    }
}

res = get_meeted_condition_unit(cgif_filter)
print("res: ", res)
