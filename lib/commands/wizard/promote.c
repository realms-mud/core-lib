//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        addCommandTemplate("demote ##Target## [to ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reportUserPromotion(object initiator, object target,
    string action, string level)
{
    object channels = load_object("/lib/dictionaries/channelDictionary.c");
    if (channels)
    {
        channels->registerUser(target);
        channels->broadcastMessage("status", 
            sprintf("%s has just %s %s to %s.\n",
                capitalize(initiator->RealName()),
                action,
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
        int isDemotion = 0;

        if (sizeof(regexp(({ command }), "^demote")))
        {
            isDemotion = 1;
        }

        if (sizeof(regexp(({ command }), "(pro|de)mote [^ ]+( to .+$|$)")))
        {
            targetName =
                regreplace(command, "^(pro|de)mote ([^ ]+)( to .+$|$)", "\\2");
        }

        string level = isDemotion ? "player" : "apprentice";
        if (sizeof(regexp(({ command }), "to (.+)")))
        {
            level = regreplace(command, "^(pro|de)mote .+ to (.+)", "\\2");
        }

        string message = 0;

        if ((level != "player") && !initiator->validWizardLevel(level))
        {
            notify_fail(configuration->decorate(
                sprintf("%s is not a valid wizard level.\n", capitalize(level)),
                "error details", "wizard commands"));
        }
        else if (targetName)
        {
            object target = findPlayer(targetName);
            if (isDemotion && (level == "player"))
            {
                ret = demoteWizardToPlayer(targetName);

                if (ret)
                {
                    message = "##InitiatorName## ##Infinitive::demote## "
                        "##TargetName## to player.";
                }
            }
            else
            {
                ret = createWizard(targetName, level);
                if (ret)
                {
                    message = sprintf("##InitiatorName## ##Infinitive::promote## "
                        "##TargetName## to %s.", level);
                }
            }

            // The target needs to be re-acquired since createWizard could
            // exec them into a new object.
            target = findPlayer(targetName);
            string* groups = (target && (member(inherit_list(target),
                "lib/realizations/wizard.c") > -1)) ? target->groups() : ({});

            if(!ret && ((!isDemotion && (member(groups, level) < 0)) || 
                (isDemotion && (member(groups, level) > -1))))
            {
                // The wizard already exists - simply promote them
                if (target)
                {
                    ret = target->setWizardLevel(level, initiator);
                    command("save", target);
                }
                else
                {
                    object userService =
                        load_object("/lib/modules/secure/dataServices/authenticationDataService.c");
                    ret = userService->setWizardLevel(targetName, level);
                }

                if (ret)
                {
                    message = sprintf("##InitiatorName## ##Infinitive::%s## "
                        "##TargetName## to %s.",
                        isDemotion ? "demote" : "promote",
                        level);

                    object logs = getDictionary("log");
                    if (logs)
                    {
                        logs->log("Promotions",
                            sprintf("(%s) %O %s wizard %O to level %O\n",
                                ctime(time()),
                                initiator->RealName(),
                                isDemotion ? "demoted" : "promoted",
                                targetName, level));
                    }
                }
            }
   
            if (message)
            {
                tell_object(initiator, configuration->decorate(
                    format(parseTemplate(message, "initiator", initiator, target), 78), 
                    "text", "command", initiator->colorConfiguration()));
                if (target)
                {
                    tell_object(target, configuration->decorate(
                        format(parseTemplate(message, "target", initiator, target), 78),
                        "text", "command", target->colorConfiguration()));
                }
            }
            else if (sizeof(groups) && member(groups, level) > -1)
            {
                notify_fail(configuration->decorate(
                    sprintf("%s is already a %s or higher. Use "
                        "demote instead if this is intended.\n", 
                        capitalize(target->RealName()), level),
                        "error details", "wizard commands"));
            }
            else if (isDemotion && sizeof(groups) &&
                (member(groups, level) < 0))
            {
                notify_fail(configuration->decorate(
                    sprintf("%s is already a lower wizard level than %s.\n"
                        "If this was intended, use promote instead.\n", 
                        capitalize(target->RealName()), level),
                    "error details", "wizard commands"));
            }

            if (ret && target)
            {
                reportUserPromotion(initiator, 
                    target, 
                    isDemotion ? "demoted": "promoted",
                    level);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Promote/demote a wizard";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The promote command will promote a player to the rank of "
        "apprentice wizard and set up their home directory and wizard "
        "permissions. If the optional 'to <level>' syntax is used, the player "
        "(or already-existing wizard) is set to the wizard level specified."
        "\n\nThe demote version of this command will reduce the level of the "
        "selected wizard to a player or, if the optional 'to <level>' "
        "syntax is used, to the specified wizard level.", 78);
}
