//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include <mtypes.h>

/////////////////////////////////////////////////////////////////////////////
public nomask void init()
{
    addCommandTemplate("say [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
        "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
    addCommandTemplate("' [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
        "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
}

/////////////////////////////////////////////////////////////////////////////
private nomask object getDictionary()
{
    return load_object("/lib/dictionaries/languageDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void speakMessage(string message, string messageTemplate,
    object initiator, object target, string language)
{
    message = regreplace(message, "(say|') *(.*)", "\\2", 1);

    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator))
    {
        foreach(object person in all_inventory(environment(initiator)))
        {
            if (person && objectp(person))
            {
                string newMessage = message;
                if (language)
                {
                    newMessage = getDictionary()->applyLanguageSkillToReceivedMessage(language, message,
                        person, initiator);
                }
                string parsedMessage = regreplace(messageTemplate, "##Message##", newMessage);

                int colorInfo = C_SAYS;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(parsedMessage, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(parsedMessage, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(parsedMessage, "other",
                        initiator, target);
                }
                tell_object(person, formatText(parsedMessage, colorInfo,
                    person));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    string messageTemplate = "##InitiatorName## ##Adverb##"
        "##Infinitive::verb####TargetPreposition####TargetName##"
        "##LanguagePreposition####Language##, `##Message##'";

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
            messageTemplate = regreplace(messageTemplate, "::verb", "::say");
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

        if (sizeof(regexp(({ command }), "-t(arget)* '*[A-Za-z]+")))
        {
            string target = regreplace(command, ".*-t(arget)* ([A-Za-z]+|'[^']+') .*", "\\2", 1);
            target = regreplace(target, "'([^']+)'", "\\1", 1);
            targetObj = present(target, environment(initiator));
            command = regreplace(command, "-t(arget)* ([A-Za-z]+)", "", 1);
            command = regreplace(command, "-t(arget)* ('[A-Za-z ]+')", "", 1);

            if (!targetObj)
            {
                messageTemplate = regreplace(messageTemplate, "##TargetName##", target);
            }
            messageTemplate = regreplace(messageTemplate, "##TargetPreposition##", " to ");
        }
        else
        {
            messageTemplate = regreplace(messageTemplate, "##TargetName##", "");
            messageTemplate = regreplace(messageTemplate, "##TargetPreposition##", "");
        }

        if (sizeof(regexp(({ command }), "-l(anguage)* [A-Za-z]+")))
        {
            language = regreplace(command, ".*-l(anguage)* ([A-Za-z]+) .*", "\\2", 1);
            command = regreplace(command, "-l(anguage)* ([A-Za-z]+)", "", 1);
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
        if (sizeof(regexp(({ command }), "(say|') -[A-Za-z]+")))
        {
            string flag = regreplace(command, "(say|') (-[A-Za-z]+).*", "\\2", 1);
            tell_object(initiator, sprintf("Command failed: The '%s' flag is not valid.\n", flag));
        }
        else
        {
            speakMessage(command, messageTemplate, initiator, targetObj, language);
        }
    }
    return ret;
}
