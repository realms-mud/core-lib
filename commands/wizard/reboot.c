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
        addCommandTemplate("reboot [-t(ime)] [##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void shutdownGame()
{
    string previousObject = object_name(previous_object());
    if (member(({ object_name(this_object()), "secure/simul_efun",
        "secure/master" }), previousObject) > -1)
    {
        shutdown();
    }
    else
    {
        printf("You cannot call this method directly.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void notifyUsers(int time)
{
    object *userList = users();
    if (sizeof(userList))
    {
        string timeLeft = userList[0]->ageString(time);

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
