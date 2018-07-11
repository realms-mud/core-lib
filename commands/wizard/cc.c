//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("cc [-r] [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void compileOneItem(string path, object initiator)
{
    object existingBlueprint;
    catch (existingBlueprint = blueprint(path); nolog);

    object *objectsToMove = ({});

    if (objectp(existingBlueprint))
    {
        objectsToMove = filter(all_inventory(existingBlueprint),
            (: (member(inherit_list($1), "lib/realizations/player.c") > -1) :));

        foreach(object item in objectsToMove)
        {
            move_object(item, "/secure/master.c");
        }

        destruct(existingBlueprint);
    }

    string logFile = sprintf("/log/%s", initiator->RealName() || "log");
    if (file_size(logFile))
    {
        rm(logFile);
    }
    tell_object(initiator, "[0;36mBuilding: " + path + "[0m\n");

    string result = catch (existingBlueprint = load_object(path));

    if (result)
    {
        result = sprintf("[0;31m%s\n[0;31;1m%s[0m", result,
            (read_file(logFile) || ""));

        tell_object(initiator, result);
        rm(logFile);
    }
    else if (existingBlueprint)
    {
        foreach(object item in objectsToMove)
        {
            move_object(item, existingBlueprint);
            tell_object(item, "[0;32;1mYour environment has been recompiled.[0m\n\n");
            command("look", item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int compile(string path, object initiator, int recurse)
{
    int ret = 0;
    if (recurse && (file_size(path) == -2))
    {
        path += "/";
    }
    else if (file_size(path) < 0)
    {
        path += ".c";
    }

    string *files = get_dir(path, 0x10);
    if (!sizeof(files) || !initiator->hasReadAccess(path))
    {
        notify_fail("No file(s) matching that criteria could be found.\n");
    }
    else if (((sizeof(files) == 1) || !recurse) &&
        (file_size(path) != -2))
    {
        ret = 1;
        compileOneItem(path, initiator);
    }
    else if(recurse)
    {
        files = filter(files, 
            (: ($1[(sizeof($1)-2)..(sizeof($1)-1)] == ".c") ||
                (file_size("/" + $1) == -2) :));

        foreach(string file in files)
        {
            if (file[0] != '/')
            {
                file = "/" + file;
            }
            ret += compile(file, initiator, 1);
        }
    }
    else
    {
        notify_fail("The -r flag must be supplied to recursively build.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) &&
        initiator->hasExecuteAccess(regreplace(command, "([^-]+)( -r|)( |$)" +
            getTargetString(initiator, command), "\\1", 1)))
    {
        string target = getTargetString(initiator, command);
        if (!target || (target == ""))
        {
            if (sizeof(regexp(({ command }), "-r")))
            {
                target = initiator->pwd();
            }
            else if (environment(initiator))
            {
                target = regreplace(object_name(environment(initiator)),
                    "^([^#]+)#*.*", "/\\1.c", 1);
            }
        }

        string targetPath = initiator->hasReadAccess(target);

        if (targetPath)
        {
            ret = compile(targetPath, initiator,
                sizeof(regexp(({ command }), "-r")));
        }
        else
        {
            notify_fail("You do not have the read access for that.\n");
        }
    }
    return ret;
}
