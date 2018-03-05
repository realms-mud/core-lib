//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/include/settings.h"
#include <mtypes.h>

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Social";
        addCommandTemplate("tell ##Target## ##Value##");
        addCommandTemplate("reply ##Value##");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object findTarget(string command)
{
    object ret = 0;
    string template = commandString(command);
    if (command && stringp(command) && template && stringp(template))
    {
        string *targetId = regexplode(command, template);

        if (sizeof(targetId) == 1)
        {
            string targetName = capitalize(regreplace(command, "tell ([A-Za-z]+) .*", "\\1", 1));

            object *target = filter(users(),
                (: return $1->Name() == $2; :), targetName);

            if (sizeof(target))
            {
                ret = target[0];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    object target = findTarget(command);
    string verb = "tell";
    if (!target)
    {
        verb = "reply";
        target = initiator->ReplyToUser();
    }
    if (objectp(target) && canExecuteCommand(command))
    {
        string message = sprintf("##InitiatorName## ##Infinitive::%s%s " +
            "##TargetName##, `" + regreplace(command,
            "(tell [^ ]+|reply) (.*)", "\\2", 1) + "'\n", verb,
                (verb == "reply") ? "## to" : "##");

        string targetMessage = formatText(parseTemplate(message, "target",
            initiator, target), C_TELL, target);

        ret = target->receiveMessage(initiator, targetMessage);

        if (ret == Blocked)
        {
            tell_object(initiator, sprintf("Your message was not sent. You "
                "have been blocked by %s.\n", capitalize(target->RealName()), 
                C_REPORT, initiator));
        }
        else if (ret == Busy)
        {
            tell_object(initiator, sprintf("Your message was not sent. %s "
                "is busy.\n", capitalize(target->RealName()),
                C_REPORT, initiator));
        }
        else
        {
            initiator->clearReplyTo();
            tell_object(initiator, formatText(parseTemplate(message,
                "initiator", initiator, target), C_TELL, initiator));
        }
    }
    return ret;
}
