//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

public nomask void SetupCommand()
{
    CommandType = "Interactions";
    addCommandTemplate("trade ##Item## with ##Target## for ##Value##");
    addCommandTemplate("accept trade from ##Target##");
    addCommandTemplate("decline trade from ##Target##");
}

public nomask int execute(string command, object initiator)
{
    int ret = 0;
    if (canExecuteCommand(command) && environment(initiator))
    {
        object service = getService("interpersonalTrading");
        string given;
        string recipient;
        string requested;
        if (sscanf(command, "trade %s with %s for %s",
            given, recipient, requested) == 3)
        {
            object target = present(lower_case(recipient),
                environment(initiator));
            if (objectp(target) &&
                function_exists("isRealizationOfLiving", target) &&
                target->isRealizationOfLiving())
            {
                ret = service->offerTrade(initiator, target,
                    present(lower_case(given), initiator),
                    present(lower_case(requested), target));
            }
        }
        else if (sscanf(command, "accept trade from %s", recipient) == 1)
        {
            object source = present(lower_case(recipient),
                environment(initiator));
            ret = service->acceptOffer(initiator, source);
        }
        else if (sscanf(command, "decline trade from %s", recipient) == 1)
        {
            object source = present(lower_case(recipient),
                environment(initiator));
            ret = service->declineOffer(initiator, source);
        }
        if (!ret)
        {
            notify_fail("The trade was not completed or offered.\n");
        }
    }
    return ret;
}

protected string synopsis(string command, string colors)
{
    return "Offer, accept, or decline a consensual item-for-item trade.";
}
