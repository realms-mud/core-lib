//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("ls [-l] [-r] [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getDirectoryToCheck(string command, object initiator)
{
    string newDirectory = getTargetString(initiator, command);

    string homeDir = sprintf("/players/%s",
        lower_case(initiator->RealName()));

    if (newDirectory == "~")
    {
        newDirectory = homeDir;
    }
    newDirectory = regreplace(newDirectory, "^~/", homeDir);
    newDirectory = regreplace(newDirectory, "^~", "/players/");

    if (!newDirectory || (newDirectory == ""))
    {
        newDirectory = initiator->pwd();
    }
    if (newDirectory[0] != '/')
    {
        newDirectory = sprintf("%s/%s", initiator->pwd(), newDirectory);
    }

    newDirectory = initiator->hasReadAccess(newDirectory);

    return newDirectory;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs string getFileState(string file, string displayName, 
    object initiator, string colorConfiguration, int width)
{
    string format;
    string widthFormat = width ? ("%-" + to_string(width) + "s") : "%s";

    if (!initiator->hasReadAccess(file) && !initiator->hasWriteAccess(file))
    {
        format = "no access";
    }
    else if ((file[sizeof(file)-2..] == ".c") && find_object(file))
    {
        displayName += "*";
        format = "compiled";
    }
    else if (file_size(file) == -2)
    {
        displayName += "/";
        format = "directory";
    }
    else
    {
        format = "normal";
    }
    return configuration->decorate(sprintf(widthFormat, displayName),
        format, "wizard commands", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getGroupInfo(string file, object initiator,
    string colorConfiguration)
{
    string readGroup = initiator->groupReadAccess(file);
    string writeGroup = initiator->groupWriteAccess(file);
    return configuration->decorate(sprintf("%-29s", sprintf("%s%s%s", readGroup,
        (((readGroup != "") && (writeGroup != "")) ? ", " : ""), writeGroup)),
        "roles", "wizard commands", colorConfiguration);      
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getFileInfo(string file, object initiator,
    string colorConfiguration)
{
    string *fileDetails = get_dir(file, 0x07);

    return configuration->decorate(sprintf("%s%s%s  ", 
                ((file_size(file) == -2) ? "d" : "-"),
                (initiator->hasReadAccess(file) ? "r" : "-"),
                (initiator->hasWriteAccess(file) ? "w" : "-")),
            "permissions", "wizard commands", colorConfiguration) +
        getGroupInfo(file, initiator, colorConfiguration) +
        configuration->decorate(sprintf("%10s  ", 
            ((file_size(file) != -2) ? to_string(fileDetails[1]) : "")),
            "file size", "wizard commands", colorConfiguration) +
        configuration->decorate(regreplace(ctime(to_int(fileDetails[2])),
            "....(.......[0-9]+:[0-9]+)...( [0-9]+)", "\\1\\2", 1),
            "message", "wizard commands", colorConfiguration) + "  " +
        getFileState(file, fileDetails[0], initiator, colorConfiguration) + "\n";
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int listFiles(string path, object initiator, 
    int recurse, int maxWidth, string colorConfiguration, int numFiles)
{
    int ret = 0;
    string *files = get_dir(path, 0x10);

    if (!sizeof(files))
    {
        notify_fail("No file(s) matching that criteria could be found.\n");
    }
    else if ((sizeof(files) == 1) || !recurse)
    {
        ret = 1;

        if (sizeof(files[0]) && (files[0][0] != '/'))
        {
            files[0] = "/" + files[0];
        }
        string *fileDetails = get_dir(files[0], 0x17);

        if (maxWidth)
        {
            int numColumns = (80 / maxWidth);
            tell_object(initiator, getFileState(files[0],
                regreplace(files[0], ".*/([^/]+)$", "\\1", 1), initiator,
                colorConfiguration, maxWidth));

            if ((numFiles % numColumns) == (numColumns - 1))
            {
                tell_object(initiator, "\n");
            }
        }
        else
        {
            tell_object(initiator, getFileInfo(files[0], initiator, colorConfiguration));
        }
    }
    else if ((sizeof(files) > 1) || recurse)
    {
        foreach(string file in files)
        {
            if (file[0] != '/')
            {
                file = "/" + file;
            }
            if (!sizeof(regexp(({ file }), "/\\.+$")))
            {
                ret += listFiles(file, initiator, recurse, maxWidth, 
                    colorConfiguration, numFiles++);
            }
        }
        tell_object(initiator, "\n");
    }
    else
    {
        notify_fail("The -r flag must be supplied to recursively list.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int maxWidth(string path, string command)
{
    int maxWidth = 0;
    if (!sizeof(regexp(({ command }), "-l")))
    {
        string *files = get_dir(path);
        foreach(string file in files)
        {
            if (sizeof(file) > maxWidth)
            {
                maxWidth = sizeof(file) + 9;
            }
        }
    }
    return maxWidth;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("ls"))
    {
        string newDirectory = getDirectoryToCheck(command, initiator);

        if (file_size(newDirectory) == -2)
        {
            if (newDirectory[sizeof(newDirectory) - 1] != '/')
            {
                newDirectory += "/";
            }
            newDirectory += "*";
        }

        if (newDirectory)
        {
            tell_object(initiator, sprintf("\x1b[0;36m[%s]\x1b[0m\n", 
                getDirectoryToCheck(command, initiator)));
            ret = listFiles(newDirectory, initiator, 1, 
                maxWidth(newDirectory, command), 
                initiator->colorConfiguration());
        }
        else if (file_size(newDirectory) == -1)
        {
            notify_fail("That directory does not exist.\n");
        }
        else
        {
            notify_fail("You do not have the read access for that.\n");
        }
    }
    return ret;
}
