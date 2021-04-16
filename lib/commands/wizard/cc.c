//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("cc [-r] [##Target##]");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void compileOneItem(string path, object initiator,
    string colorConfiguration)
{
    object existingBlueprint;
    catch (existingBlueprint = blueprint(path); nolog);

    object *objectsToMove = ({});

    if (objectp(existingBlueprint))
    {
        objectsToMove = filter(all_inventory(existingBlueprint),
            (: (member(inherit_list($1), "/lib/realizations/player.c") > -1) :));

        foreach(object item in objectsToMove)
        {
            move_object(item, "/secure/master.c");
        }

        destruct(existingBlueprint);
    }

    string logFile = "/log/log"; 

    if (file_size(logFile))
    {
        rm(logFile);
    }
    tell_object(initiator, configuration->decorate(sprintf("Building: %s\n",
        path), "message", "wizard commands", colorConfiguration));

    string result = catch (existingBlueprint = load_object(path));

    if (result)
    {
        result = configuration->decorate(result,
                "error message", "wizard commands", colorConfiguration) +
            configuration->decorate((read_file(logFile) || driver_info(-44)),
                "error message", "wizard commands", colorConfiguration);

        tell_object(initiator, result);
        rm(logFile);
    }
    else if (existingBlueprint)
    {
        foreach(object item in objectsToMove)
        {
            move_object(item, existingBlueprint);
            tell_object(item, configuration->decorate(
                "Your environment has been recompiled.\n\n",
                "error message", "wizard commands", colorConfiguration));
            command("look", item);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int compile(string path, object initiator, 
    string colorConfiguration, int recurse)
{
    int ret = 0;

    string directoryPath = path;
    if (recurse && (file_size(path) == -2))
    {
        path += "/*";
    }
    else if ((file_size(path) < 0) && (path[sizeof(path)-2..] != ".c"))
    {
        path += ".c";
    }

    string *files = get_dir(path, 0x10) - 
        ({ (directoryPath + "/."), (directoryPath + "/..") });

    if (!sizeof(files) || !initiator->hasReadAccess(path))
    {
        notify_fail("No file(s) matching that criteria could be found.\n");
    }
    else if (((sizeof(files) == 1) || !recurse) &&
        (file_size(path) > -1))
    {
        ret = 1;
        compileOneItem(path, initiator, colorConfiguration);
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
            ret += compile(file, initiator, colorConfiguration, 1);
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
                initiator->colorConfiguration(),
                sizeof(regexp(({ command }), "-r")), 0);
        }
        else
        {
            notify_fail("You do not have the read access for that.\n");
        }
    }
    return ret;
}
