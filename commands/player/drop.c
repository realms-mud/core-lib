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
            targets += ({ getTarget(initiator, command) });
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
                    if (!target->drop())
                    {
                        displayMessage("##InitiatorName## ##Infinitive::drop## " +
                            target->query("name") + ".\n", initiator);
                    }
                }
            }
        }
    }
    return ret;
}
