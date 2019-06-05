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
        CommandType = "Interactions";
        addCommandTemplate("drop [(-a|-f)+] ##Item##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object *targets = ({});
        string targetString = getTargetString(initiator, command);

        if (targetString == "all")
        {
            targets += filter(all_inventory(initiator),
                (: function_exists("drop", $1) &&
                    !$1->query("undroppable") :));
        }
        else if (sizeof(regexp(({ command }), "[0-9]+ (coin|coins|money)")))
        {
            int amount = to_int(regreplace(command, "[^0-9]*([0-9]+) (coin|coins|money).*", "\\1", 1));
            if (amount > 0)
            {
                targets += ({ initiator->transferMoneyFrom(amount) });
            }
            if (!sizeof(targets - ({ 0 })))
            {
                tell_object(initiator, sprintf("You cannot drop %d coins.\n",
                    amount));
            }
        }
        else if ((command == "drop coin") && initiator->Money())
        {
            targets += ({ initiator->transferMoneyFrom(1) });
        }
        else if (sizeof(regexp(({ command }), "(all|) (coin|coins|money)")) &&
            initiator->Money())
        {
            targets += ({ initiator->transferMoneyFrom() });
        }
        else if (sizeof(regexp(({ command }), "-a")))
        {
            targets += filter(all_inventory(initiator),
                (: function_exists("drop", $1) &&
                    !$1->query("undroppable") &&
                    $1->id($2) :), targetString);
        }
        else if ((member(inherit_list(initiator), "lib/realizations/wizard.c") > -1) &&
            present_clone(targetString, initiator))
        {
            targets += ({ present_clone(targetString, initiator) });
        }
        else
        {
            targets += ({ getTarget(initiator, command, TargetInventory) });
        }
        targets -= ({ 0 });

        if (sizeof(targets))
        {
            ret = 1;
            foreach(object target in targets)
            {
                if (!initiator->isEquipped(target) ||
                    sizeof(regexp(({ command }), "-f")))
                {
                    if (!function_exists("drop", target) &&
                        (member(inherit_list(initiator),
                            "lib/realizations/wizard.c") > -1))
                    {
                        move_object(target, environment(initiator));
                    }
                    if (!target->drop())
                    {
                        displayMessage("##InitiatorName## ##Infinitive::drop## " +
                            (target->query("name") || target->Name()) + ".\n", initiator);
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Drop the chosen item(s) from the player's inventory on to "
        "the ground in their environment.";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-*[a-zA-Z]+).*", "\\1");

    switch (parsedFlag)
    {
        case "-a":
        {
            ret = "This option will attempt to drop everything in the player's "
                "inventory that matches the criteria following the -a flag. "
                "For example:\n\t> drop -a potion\nThis would "
                "drop every potion in the player's possession.";
            break;
        }
        case "-f":
        {
            ret = "This option will attempt to force-drop an item in the "
                "player's inventory. By default, drop will not drop equipped "
                "items and this flag will override that behavior.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Drop will move the specified item from the player's "
        "inventory to the environment in which the player currently stands. "
        "There are a few keywords that can affect this command's behavior, "
        "notably:\n\t> drop all\nThis permutation of the command will attempt "
        "to drop all items in the player's inventory.\n\nIn order to drop "
        "money, the syntax is slightly different and can take any of the "
        "following forms:\n\t> drop coin\n\t> drop 2 coins\n\t"
        "> drop all coins\n\t> drop money\nThese will drop one coin, two coins, "
        "or all of the player's money.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: get, give";
}
