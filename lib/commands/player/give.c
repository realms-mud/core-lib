//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Interactions";
    addCommandTemplate("give [(-a|-f)+] [##Item##] [to ##Target##]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && sizeof(regexp(({ command }),
        "give ((-a|-f)+)* *.+ to .+")))
    {
        object *targets = ({});

        string targetString = getTargetString(initiator, 
            regreplace(command, " to .*", "", 1));

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
                tell_object(initiator, sprintf("You cannot give %d coins.\n",
                    amount));
            }
        }
        else if (sizeof(regexp(({ command }), "coin[^s]")) && initiator->Money())
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
        else
        {
            targets += ({ getTarget(initiator, regreplace(command, " to .*$", "", 1)) });
        }
        targets -= ({ 0 });

        if (sizeof(targets))
        {
            object receiver = getTarget(initiator,
                regreplace(command, "give .* to (.*)$", "give \\1", 1));

            ret = 1;
            foreach(object target in targets)
            {
                if (!initiator->isEquipped(target) ||
                    sizeof(regexp(({ command }), "-f")))
                {
                    if (!target->drop())
                    {
                        string itemName = target->query("name");
                        if ((member(inherit_list(target), "lib/items/money.c") > -1))
                        {
                            itemName += " totaling " + target->query("value") +
                                " in value";
                            receiver->transferMoneyTo(target);
                        }
                        else
                        {
                            move_object(target, receiver);
                        }
                        displayMessage("##InitiatorName## ##Infinitive::give## " 
                            "##TargetName## " + itemName + ".\n",
                            initiator, receiver);
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
    return "Give the chosen item(s) to another character.";
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
            ret = "This option will attempt to give everything in the player's "
                "inventory that matches the criteria following the -a flag. "
                "For example:\n\t> give -a potion to george\nThis would "
                "give every potion in the player's possession to George.";
            break;
        }
        case "-f":
        {
            ret = "This option will attempt to force-give an item in the "
                "player's inventory. By default, give will not give equipped "
                "items and this flag will override that behavior.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Give will move the specified item from the player's "
        "inventory to another character. There are a few keywords that can "
        "affect this command's behavior. In order to give "
        "money, the syntax is slightly different and can take any of the "
        "following forms:\n\t> give coin to fred\n\t> give 2 coins to fred\n\t"
        "> give all coins to fred\n\t> give money to fred\nThese will get one "
        "coin, two coins or all coins to Fred.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: drop, get";
}
