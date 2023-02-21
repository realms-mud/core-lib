//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "General";
    addCommandTemplate("harvest [-s(tatus|)] [.*]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        string resource = 0;
        int showStatus = 0;
        if (sizeof(regexp(({ command }), "^harvest (-s(tatus|))")) ||
            (command == "harvest"))
        {
            resource = (command == "harvest") ? 0 :
                regreplace(command, "harvest (-s(tatus|)) (.*)", "\\3", 1);

            showStatus = 1;
        }
        else
        {
            resource = regreplace(command, "harvest (.*)", "\\1", 1);
        }
        object location = environment(initiator);

        if (showStatus)
        {
            ret = 1;
            tell_object(initiator, location->harvestStatistics(initiator, resource));
        }
        else
        {
            object element = location->harvestResource(resource, initiator);
            if (element)
            {
                string message;
                if (initiator->canCarry(element))
                {
                    move_object(element, initiator);
                    message = sprintf("##InitiatorName## ##Infinitive::harvest## "
                        "some %s.", resource);
                }
                else
                {
                    move_object(element, environment(initiator));
                    message = sprintf("##InitiatorName## ##Infinitive::harvest## "
                        "some %s and sets it on the ground.", resource);
                }
                displayMessage(message, initiator);
            }
            else 
            {
                tell_object(initiator, sprintf("You cannot harvest %s.\n", resource));
            }
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "";
}
