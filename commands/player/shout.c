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
        CommandType = "Social";
        addCommandTemplate("shout [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [.*]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getDictionary()
{
    return load_object("/lib/dictionaries/languageDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void shoutMessage(string message, string messageTemplate,
    object initiator, string language)
{
    message = regreplace(message, "shout *(.*)", "\\1", 1);

    object *targets = filter(users(), (: return !$1->isEarmuffed(); :));
    if (member(targets, initiator) < 0)
    {
        // Add initiator if they're earmuffed.
        targets += ({ initiator });
    }

    object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

    foreach(object target in targets)
    {
        string newMessage = message;
        if (language)
        {
            newMessage = getDictionary()->applyLanguageSkillToReceivedMessage(language, message,
                target, initiator);
        }
        string parsedMessage = regreplace(messageTemplate, "##Message##", newMessage);

        if (target == initiator)
        {
            parsedMessage = parseTemplate(parsedMessage, "initiator", initiator,
                target);
        }
        else
        {
            parsedMessage = parseTemplate(parsedMessage, "other",
                initiator, target);
        }
        tell_object(target, configuration->decorate(
            format(parsedMessage, 78), "message", "shout",
            target->colorConfiguration()));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    string messageTemplate = "##InitiatorName## ##Adverb##"
        "##Infinitive::verb####LanguagePreposition##"
        "##Language##, `##Message##'";

    if (canExecuteCommand(command))
    {
        ret = 1;
        object targetObj = 0;
        string language = 0;

        if (sizeof(regexp(({ command }), "-v(erb)* [A-Za-z]+")))
        {
            string verb = regreplace(command, ".*-v(erb)* ([A-Za-z]+) .*", "\\2", 1);
            command = regreplace(command, "-v(erb)* ([A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "::verb", "::" + verb);
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "::verb", "::shout");
        }

        if (sizeof(regexp(({ command }), "-a(dverb)* [A-Za-z]+")))
        {
            string adverb = regreplace(command, ".*-a(dverb)* ([A-Za-z]+) .*", "\\2 ", 1);
            command = regreplace(command, "-a(dverb)* ([A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "##Adverb##", adverb);
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##Adverb##", "");
        }

        if (sizeof(regexp(({ command }), "-l(anguage)* (high elven|[A-Za-z]+)")))
        {
            language = regreplace(command, ".*-l(anguage)* (high elven|[A-Za-z]+) .*", "\\2", 1);
            command = regreplace(command, "-l(anguage)* (high elven|[A-Za-z]+)", "", 1);
            messageTemplate = regreplace(messageTemplate, "##Language##", 
                getDictionary()->getSpokenLanguage(language, initiator));
            messageTemplate = regreplace(messageTemplate, "##LanguagePreposition##", " in ");
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##Language##", "");
            messageTemplate = regreplace(messageTemplate, "##LanguagePreposition##", "");
        }

        // This will kill the other flags
        if (sizeof(regexp(({ command }), "(shout|') -[A-Za-z]+")))
        {
            string flag = regreplace(command, "(shout|') (-[A-Za-z]+).*", "\\2", 1);
            tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
        }
        else
        {
            shoutMessage(command, messageTemplate, initiator, language);
        }
    }
    return ret;
}
