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
        addCommandTemplate("promote ##Target## [to ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reportUserPromotion(object initiator, object target,
    string level)
{
    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    if (channels)
    {
        channels->registerUser(target);
        channels->broadcastMessage("status", 
            sprintf("%s has just promoted %s to %s.\n",
                capitalize(initiator->RealName()), 
                capitalize(target->RealName()), 
                level));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("promote"))
    {
        string targetName = 0;
        int canDemote = 0;

        if (sizeof(regexp(({ command }), "-d")))
        {
            canDemote = 1;
        }

        if (sizeof(regexp(({ command }), "promote [^ ]+( to .+$|$)")))
        {
            targetName =
                regreplace(command, "^promote ([^ ]+)( to .+$|$)", "\\1");
        }

        string level = "apprentice";
        if (sizeof(regexp(({ command }), "to (.+)")))
        {
            level = regreplace(command, "^promote .+ to (.+)", "\\1");
        }

        if (targetName)
        {
            object target = findPlayer(targetName);

            ret = createWizard(targetName, level);

            // The target needs to be re-acquired since createWizard could
            // exec them into a new object.
            target = findPlayer(targetName);

            if (ret)
            {
                object logs = getDictionary("log");
                if (ret && logs)
                {
                    logs->log("CreateWizard",
                        sprintf("%O promoted %O to %O\n",
                            initiator->RealName(), targetName, level));
                }
            }
            else
            {
                // The wizard already exists - simply promote them
                if (target)
                {
                    ret = 1;
                    target->setWizardLevel(level, initiator);
                    command("save", target);
                }
                else
                {
                    object userService =
                        load_object("/lib/modules/secure/dataServices/authenticationDataService.c");
                    ret = userService->setWizardLevel(targetName, level);
                }
            }

            if (target)
            {
                reportUserPromotion(initiator, target, level);
            }
        }
    }
    return ret;
}
