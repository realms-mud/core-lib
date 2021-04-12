//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/include/settings.h"

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Social";
    addCommandTemplate("tell ##Target## ##Value##");
    addCommandTemplate("reply ##Value##");
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

        object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

        string targetMessage = configuration->decorate(
            format(parseTemplate(message, "target", initiator, target), 78),
            "message", "tell", target->colorConfiguration());

        ret = target->receiveMessage(targetMessage, initiator);

        if (ret == Blocked)
        {
            tell_object(initiator, configuration->decorate(
                format(sprintf("Your message was not sent. You "
                "have been blocked by %s.\n", 
                    capitalize(target->RealName())), 78), 
                "block", "tell", initiator->colorConfiguration()));
        }
        else if (ret == Busy)
        {
            tell_object(initiator, configuration->decorate(
                format(sprintf("Your message was not sent. %s "
                "has %s status set to busy.\n",
                    capitalize(target->RealName()), target->Possessive()), 78),
                "busy", "tell", initiator->colorConfiguration()));
        }
        else
        {
            initiator->clearReplyTo();
            tell_object(initiator, configuration->decorate(
                format(parseTemplate(message, "initiator", initiator, target), 78),
                "message", "tell", initiator->colorConfiguration()));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Send a message to a specific person on the mud";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Tell will send a message to a specific person on the "
        "mud. During a conversation such as this, the 'reply' "
        "command can be used to direct a message back to the last "
        "person who has sent a 'tell' to you.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: shout, whisper, reply, say, and set";
}
