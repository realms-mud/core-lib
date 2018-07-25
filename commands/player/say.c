//******************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include <mtypes.h>

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Social";
        addCommandTemplate("say [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
        addCommandTemplate("' [-v(erb|) ##Verb##] [-a(dverb|) ##Adverb##] "
            "[-l(anguage|) ##Language##] [-t(arget|) ##Target##] [.*]");
    }
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

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning()
{
    return "[0;31;1m<Message to speak>[0m";
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand)
{
    return "Send a message to everyone in your environment";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-v":
        {
            ret = "This option will replace the verb displayed as part of "
                "the 'say' message. For example:\n\t[0;37m> say -v grumble "
                "I'm grumpy!\n\t[0;32mYou grumble, `I'm grumpy!'[0m\n"
                "[0;36mOthers users would then see:\n"
                "\t[0;32mBob grumbles, `I'm grumpy!'[0m\n";
            break;
        }
        case "-a":
        {
            ret = "This option will add an adverb to "
                "the 'say' message. For example:\n\t[0;37m> say -a sarcastically "
                "You're my hero!\n\t[0;32mYou sarcastically say, `You're my hero!'[0m\n"
                "[0;36mOthers users would then see:\n"
                "\t[0;32mBob sarcastically says, `You're my hero!'[0m\n";
            break;
        }
        case "-l":
        {
            ret = "This option will translate the message you wish to say into "
                "the given language - or at least attempt to do so. Your skill "
                "in the target language will determine whether or not it is "
                "translated appropriately or becomes gibberish. Those in the "
                "environment will then use their skill to translate the message "
                "back to English. For example if you have no skill in a "
                "language, you might see:\n\t[0;37m> say -l orcish "
                "I should say something nice.\n\t[0;32mYou say in complete "
                "gibberish, `Blarg nukuleve zog forgla bup'\n"
                "[0;36mOthers users would see:\n"
                "\t[0;32mBob says in complete gibberish, `Blarg nukuleve zog "
                "forgla bup'\n[0;36mMeanwhile, if you do know a language you might "
                "see:\n\t[0;37m> say -l elven I should say something nice."
                "\n\t[0;32mYou say in elven, `I should say something nice.'\n"
                "[0;36mOthers users that have a high skill in elven would see:"
                "\n\t[0;32mBob says in elven, `I should say something nice.'\n"
                "[0;36mOthers users that have no skill in elven would see:"
                "\n\t[0;32mBob says in elven, `Naur wu simildin welana loomen'\n"
                "[0;36mIt is important to note that knowledge of a language is "
                "a range and, so too, is one's ability to speak and translate "
                "it. You will go from being able to speak/understand nothing "
                "to brokenly speaking or partially understanding all the way "
                "through being completely fluent.[0;36m\n";
            break;
        }
        case "-t":
        {
            ret = "This option will allow you to speak a message to a specific "
                "target. For example:\n\t[0;37m> say -t Fred "
                "Hi Fred!\n\t[0;32mYou say to Fred, `Hi Fred!'[0m\n"
                "[0;36mFred would then see:\n"
                "\t[0;32mBob says to you, `Hi Fred!'[0m\n"
                "[0;36mOthers users would then see:\n"
                "\t[0;32mBob says to Fred, `Hi Fred!'[0m\n";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand)
{
    return format("Say allows a player to display a message to all players "
        "located in the same room where he or she is standing. The character ' "
        "can be used as an abbreviation for say to save time.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand)
{
    return "See also: tell, whisper, reply, and shout";
}
