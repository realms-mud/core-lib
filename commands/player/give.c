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
        CommandType = "Interactions";
        addCommandTemplate("give [(-a|-f)+] [##Item##] [to ##Target##]");
    }
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
