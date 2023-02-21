//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("reboot [-t(ime)] [##Value##]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask void shutdownGame()
{
    string previousObject = object_name(previous_object());
    if (member(({ object_name(this_object()), "/secure/simul_efun",
        "/secure/master" }), previousObject) > -1)
    {
        shutdown();
    }
    else
    {
        printf("You cannot call this method directly.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string timeLeft(int time)
{
    // Eek! Magic numbers everywhere! As soon as I'm getting paid more than
    // $0/hr for this, I'll fix it...
    return sprintf("%s%s%s%s%s",
        ((time / 31557600) ? sprintf("%d year%s ", (time / 31557600),
        ((time / 31557600) == 1) ? "" : "s") : ""),
            ((time / 86400) ? sprintf("%d day%s ", ((time % 31557600) / 86400),
        (((time % 31557600) / 86400) == 1) ? "" : "s") : ""),
                ((time / 3600) ? sprintf("%d hour%s ", ((time % 86400) / 3600),
        (((time % 86400) / 3600) == 1) ? "" : "s") : ""),
                    ((time / 60) ? sprintf("%d minute%s ", ((time % 3600) / 60),
        (((time % 3600) / 60) == 1) ? "" : "s") : ""),
        sprintf("%d second%s", (time % 60), (((time % 60) == 1) ? "" : "s")));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void notifyUsers(int time)
{
    object *userList = users();
    if (sizeof(userList))
    {
        string timeLeft = timeLeft(time);

        foreach(object user in userList)
        {
            tell_object(user, configuration->decorate(
                sprintf("****************************************************\n"
                    "WARNING: The MUD will reboot in %s\n"
                    "****************************************************\n",
                    timeLeft), "system message", "shout", user->colorConfiguration()));
        }
    }

    // Be sure to notify once more when roughly 10 seconds are left.
    time = (time > 60) ? (time - 60) : (time - 50);

    if (time > 0)
    {
        call_out("notifyUsers", time, time);
    }
    else
    {
        shutdownGame();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("reboot"))
    {
        ret = 1;
        int time = 60;
        if (sizeof(regexp(({ command }), "-t(ime)* *[0-9]+$")))
        {
            time = to_int(regreplace(command, ".*-t(ime)* *([0-9]+)$", "\\2", 1));
        }
        else if (sizeof(regexp(({ command }), "-t(ime)*")))
        {
            ret = 0;
            notify_fail("The -t(ime) flag must have a valid wait duration.\n");
        }

        if (ret)
        {
            tell_object(initiator, configuration->decorate(
                "Reboot initiated.\n", "message", "wizard commands", 
                initiator->colorConfiguration()));

            call_out("notifyUsers", 0, time);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Reboot the mud";
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
            ret = "This option will overrid the default time of 60 seconds.";
            break;
        }
    }
    return format(ret, 72);
}
/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The reboot command will reboot the mud. If the optional "
        "-t parameter is passed, the chosen time will be used for the "
        "countdown instead of the default 60 seconds.", 78);
}
