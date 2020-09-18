//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("patch [-t ##Target##] [-f ##Function##] [-v ##Values##] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private int sortArray(mixed a, mixed b)
{
    string compA;
    string compB;

    if (mappingp(a) && mappingp(b))
    {
        compA = this_object()->convertDataToString(a);
        compB = this_object()->convertDataToString(b);
    }
    else
    {
        compA = to_string(a);
        compB = to_string(b);
    }

    return compA > compB;
}

/////////////////////////////////////////////////////////////////////////////
private string convertDataToString(mixed data)
{
    string ret = "";

    if (objectp(data))
    {
        ret += program_name(data);
    }
    else if (pointerp(data) && sizeof(data))
    {
        ret += "({ ";
        data = sort_array(data, "sortArray");
        foreach(mixed element in data)
        {
            ret += convertDataToString(element) + ", ";
        }
        ret += "})";
    }
    else if (mappingp(data))
    {
        ret += "([ ";
        mixed *indices = sort_array(m_indices(data), "sortArray");
        foreach(mixed index in indices)
        {
            ret += convertDataToString(index) + ": " + convertDataToString(data[index]) + ", ";
        }
        ret += "])";
    }
    else
    {
        ret += to_string(data);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private object getPatchTarget(string command, object initiator)
{
    object target = 0;
    if (sizeof(regexp(({ command }), "-t [^-]+")))
    {
        string targetString = regreplace(command, ".*-t ([^-]+)( .*|$)", "\\1", 1);

        target = present(targetString, initiator) ||
            present(targetString, environment(initiator)) ||
            find_object(targetString);

        if (!target)
        {
            string targetPath = initiator->hasReadAccess(targetString);

            if (targetPath && (file_size(targetPath) > 0))
            {
                catch (target = load_object(targetPath));
            }
        }
    }
    return target;
}

/////////////////////////////////////////////////////////////////////////////
private string getPatchFunction(string command, object initiator)
{
    string methodName = 0;
    if (sizeof(regexp(({ command }), "-f [A-Za-z_0-9]+")))
    {
        methodName = regreplace(command, ".*-f ([A-Za-z_0-9]+).*", "\\1", 1);
    }
    return methodName;
}

/////////////////////////////////////////////////////////////////////////////
private mixed *getPatchParameters(string command, object initiator)
{
    mixed *parameters = 0;
    if (sizeof(regexp(({ command }), "-v [^-]+")))
    {
        mixed *paramList = regexplode(regreplace(command, ".*-v ([^-]+)( .*|$)", "\\1", 1),
            ", *") - ({ ",", ", " });
        parameters = ({ });
        foreach(mixed parameter in paramList)
        {
            if (to_object(parameter))
            {
                parameters += ({ to_object(parameter) });
            }
            else if (sizeof(regexp(({ parameter }), "[0-9]*\\.[0-9]+")))
            {
                parameters += ({ to_float(parameter) });
            }
            else if (to_int(parameter))
            {
                parameters += ({ to_int(parameter) });
            }
            else
            {
                parameters += ({ to_string(parameter) });
            }
        }
    }
    return parameters;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("patch"))
    {
        object target = getPatchTarget(command, initiator);
        string methodName = getPatchFunction(command, initiator);
        mixed *parameters = getPatchParameters(command, initiator);

        if (objectp(target))
        {
            if (methodName && function_exists(methodName, target))
            {
                ret = 1;
                tell_object(initiator, sprintf("Function '%s' found in %O.\n",
                    methodName, target));

                mixed output = apply(#'call_other, target, methodName, parameters);

                tell_object(initiator, sprintf("Returned: %s\n",
                    convertDataToString(output)));
            }
            else
            {
                notify_fail(sprintf("Function '%s' does not exist in %O.\n",
                    to_string(methodName), target));
            }
        }
        else
        {
            notify_fail(sprintf("Couldn't find object '%O'.\n", target));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Call a function on an object";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-t":
        {
            ret = "Specify the target object that the method is going "
                "to be called on.";
            break;
        }
        case "-f":
        {
            ret = "Specify the method to execute.";
            break;
        }
        case "-v":
        {
            ret = "Specify a comma-delimited list of parameters to be "
                "passed into the function being executed.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The patch command will execute the function (-f "
        "<function>) on a target object/blueprint file (-t <target>) using "
        "the parameters specified (-p <parameters>).", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: clone";
}
