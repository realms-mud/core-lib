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
        CommandType = "Wizard";
        addCommandTemplate("rm [-r] [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int removeFile(string path, object initiator, int recurse)
{
    int ret = 0;
    if (recurse && (file_size(path) == -2))
    {
        path += "/";
    }

    string *files = get_dir(path, 0x10);
    if (!initiator->hasWriteAccess(path))
    {
        notify_fail("No file(s) matching that criteria could be found.\n");
    }
    else if (!recurse || !sizeof(files))
    {
        if (file_size(path) == -2)
        {
            ret = rmdir(path);
        }
        else
        {
            ret = rm(path);
        }
    }
    else if (recurse)
    {
        foreach(string file in files)
        {
            if (file[0] != '/')
            {
                file = "/" + file;
            }
            ret += removeFile(file, initiator, 
                file_size(file) == -2);
        }
        rmdir(path);
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

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("rm"))
    {
        string file = regreplace(command, "^rm( -r|) (.+)", "\\2");

        string filePath = initiator->hasWriteAccess(file);

        if (filePath)
        {
            if (file_size(filePath) != -1)
            {
                ret = removeFile(filePath, initiator, 
                    sizeof(regexp(({ command }), "-r")));
            }
            else
            {
                tell_object(initiator, format(sprintf("The file '%s' does not exist.",
                    filePath), 78));
            }
        }
        else
        {
            tell_object(initiator, format(sprintf(
                "You do not have write access to '%s'", file || "???"), 78));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    if(parsedFlag == "-r")
    {
        ret = "This option will allow you to recursively delete a file "
            "or directory";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand)
{
    return "Remove/delete a file.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand)
{
    return format("The rm command will remove the specified file provided the "
        "user has write access.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand)
{
    return "See also: cp and mv";
}
