//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
#include <mtypes.h>

#define Speech "\x1b[0;33m"
#define Desc "\x1b[0;36m"
#define End "\x1b[0m"
#define Stat(x) sprintf("\x1b[0;34;1m[%s]\x1b[0m", x)
#define Action(x) sprintf("\x1b[0;31m[%s]\x1b[0m", x)
#define Highlight(x) sprintf("\x1b[0;35m%s\x1b[0m", x)

private string MaterialAttributes = "lib/modules/materialAttributes.c";
private int ignoreTalk = 0;
private int SetupCompleted = 0;

private mapping responseKeys = ([]);
private mapping topics = ([ ]);

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{

}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        if (!SetupCompleted)
        {
            Setup();
            SetupCompleted = 1;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *listTopics()
{
    return m_indices(topics);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isRepeatable(string id)
{
    return(member(topics, id) && member(topics[id], "is repeatable"));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopic(string id, string template)
{
    if (!member(topics, id))
    {
        topics[id] = ([
            "template": template
        ]);
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addTopic: Topic '%s'"
            " already exists.\n", id));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addConditionalTopicAddendum(string id,
    mapping condition, string template)
{

}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addRepeatableTopic(string id, string template)
{
    addTopic(id, template);
    topics[id]["is repeatable"] = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicPrerequisite(string id, mapping prerequisite)
{
    if (member(topics, id) && (sizeof(prerequisite) == 1))
    {
        if (!addPrerequisite(m_indices(prerequisite)[0],
            prerequisite[m_indices(prerequisite)[0]], id))
        {
            raise_error(sprintf("ERROR - baseConversation.c, addTopicPrerequisite:"
                " The passed prerequisite to '%s' is invalid.\n", id));
        }
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addTopicPrerequisite:"
            " Could not add the prerequisite to '%s'. Make sure that "
            "the topic exists.\n", id));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicEvent(string id, string event)
{
    if (member(topics, id))
    {
        topics[id]["event"] = event;
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addTopicEvent: "
            "Topic '%s' does not exist.\n", id));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addTopicTrigger(string id, string event)
{
    if (member(topics, id))
    {
        topics[id]["trigger"] = event;
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addTopicTrigger: "
            "Topic '%s' does not exist.\n", id));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponse(string id, string selection, string template)
{
    if (member(topics, id))
    {
        if (!member(topics[id], "responses"))
        {
            topics[id]["responses"] = ([]);
        }

        string response = sprintf("%s#%s", id, selection);
        if (!member(topics[id]["responses"], response))
        {
            topics[id]["responses"][response] = ([
                "selection":selection,
                "template": template
            ]);
        }
        else
        {
            raise_error(sprintf("ERROR - baseConversation.c, addResponse: "
                "The response '%s' already exists.\n", selection));
        }
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addResponse: "
            "Topic '%s' does not exist.\n", id));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponsePrerequisite(string id, string selection, mapping prerequisite)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response) &&
        (sizeof(prerequisite) == 1))
    {
        if (!addPrerequisite(m_indices(prerequisite)[0],
            prerequisite[m_indices(prerequisite)[0]], response))
        {
            raise_error(sprintf("ERROR - baseConversation.c, addResponsePrerequisite:"
                " The passed prerequisite to '%s' is invalid.\n", selection));
        }
    }
    else
    {
        raise_error("ERROR - baseConversation.c, addResponsePrerequisite: "
            "Could not add the prerequiste. Check to make sure that "
            "the topic and response exist.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponseEvent(string id, string selection, string event)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response))
    {
        topics[id]["responses"][response]["event"] = event;
    }
    else
    {
        raise_error("ERROR - baseConversation.c, addResponseEvent: "
            "Could not add the event. Check to make sure that the "
            "topic and response exist.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private int isValidEffect(mapping effectMap)
{
    int ret = 0;
    string *validEffects = ({ "opinion", "attack", "move", "give", "vanish" });
    string *effects = m_indices(effectMap);
    if (sizeof(effects))
    {
        ret = 1;
        foreach(string effect in effects)
        {
            ret &&= member(validEffects, effect) > -1;

            switch (effect)
            {
                case "vanish":
                case "opinion": 
                {
                    ret &&= intp(effectMap[effect]);
                    break;
                }
                case "move":
                case "give":
                {
                    ret &&= stringp(effectMap[effect]) &&
                        file_size(effectMap[effect]) &&
                        load_object(effectMap[effect]);
                    break;
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponseEffect(string id, string selection, mapping effect)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response) && isValidEffect(effect))
    {
        topics[id]["responses"][response]["effect"] = effect;
    }
    else
    {
        raise_error("ERROR - baseConversation.c, addResponseEffect: "
            "Could not add the event. Check to make sure that the "
            "topic and response exist and that the effect is valid.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addResponseTopic(string id, string selection, string topic)
{
    string response = sprintf("%s#%s", id, selection);
    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response) && member(topics, topic))
    {
        topics[id]["responses"][response]["topic"] = topic;
    }
    else
    {
        raise_error("ERROR - baseConversation.c, addResponseTopic: "
            "Could not add the link to the topic. Check to make sure that the "
            "topic and response exist.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object messageParser()
{
    return load_object("/lib/core/messageParser.c");
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidLiving(object livingCheck)
{
    return (livingCheck && objectp(livingCheck) &&
        (member(inherit_list(livingCheck), MaterialAttributes) > -1));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string parseTemplate(string template, string perspective,
    object initiator, object target)
{
    string message = template;
    // ##Infinitive::verb##
    // ##InitiatorName## - Initiator's name
    // ##InitiatorPossessive[::Name]## - Initiator possessive / your / Name's
    // ##InitiatorObjective## - Initiator's objective / you
    // ##InitiatorSubjective## - Initiator's subjective/pronoun / you
    // ##Target[NPOS]## - Target's (one of above 4)
    // ##HitDictionary## - random word from the hit dictionary (slash/slashes,
    //   chop/chops)
    // ##SimileDictionary## - random word from the simile dictionary

    // dictionary calls must be done first!
    int isSecondPerson = (perspective == "initiator");

    message = messageParser()->parseVerbs(message, perspective == "target");
    message = regreplace(message, "##ResponseInfinitive::([^#]+)##", "##Infinitive::\\1##", 1);
    message = messageParser()->parseVerbs(message, isSecondPerson);

    if (initiator && objectp(initiator))
    {
        message = messageParser()->parseSimileDictionary(message, target);
        message = messageParser()->parseVerbDictionary(message,
            "HitDictionary", target);
    }

    if (isValidLiving(initiator))
    {
        message = messageParser()->parseTargetInfo(message, "Initiator",
            initiator, isSecondPerson);
        message = messageParser()->parseTargetInfo(message, "Actor",
            initiator, 0);
    }

    if (isValidLiving(target))
    {
        isSecondPerson = (perspective == "target");
        message = messageParser()->parseTargetInfo(message, "Target",
            target, isSecondPerson);
    }

    message = messageParser()->capitalizeSentences(message);

    while (sizeof(regexp(({ message }), "@C@")))
    {
        string firstCharacter = capitalize(regreplace(message, ".*@C@(.).*", "\\1"));
        message = regreplace(message, "@C@(.)", firstCharacter);
    }
    message = format(message, 78);

    // Apply colors
    message = regreplace(message, "@S@", Speech, 1);
    message = regreplace(message, "@D@", Desc, 1);
    message = regreplace(message, "@A@((.+))@E@", Stat("\\1"), 1);
    message = regreplace(message, "@I@(.+)@E@", Action("\\1"), 1);
    message = regreplace(message, "@H@(.+)@E@", Highlight("\\1"), 1);

    message += End;
    return message;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void displayMessage(string message, object initiator,
    object target)
{
    // This annoying loop handles the fact that everyone has different
    // setting for color.
    if (environment(initiator))
    {
        foreach(object person in all_inventory(environment(initiator)))
        {
            if (person && objectp(person))// && interactive(person))
            {
                string parsedMessage;
                int colorInfo = C_EMOTES;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(message, "initiator", initiator,
                        target);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(message, "target",
                        initiator, target);
                }
                else
                {
                    parsedMessage = parseTemplate(message, "other",
                        initiator, target);
                }
                tell_object(person, parsedMessage);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void executeResponseEffect(mapping effects,
    object actor, object owner)
{
    if (member(effects, "opinion"))
    {
        owner->alterOpinionOf(actor, effects["opinion"]);
    }
    if (member(effects, "attack"))
    {
        owner->attack(actor);
    }
    if (member(effects, "move"))
    {
        tell_room(environment(owner), sprintf("%s leaves.\n", owner->Name()));
        move_object(owner, effects["move"]);
    }
    if (member(effects, "give"))
    {
        object gift = present_clone(effects["give"], owner);
        if (gift)
        {
            if (owner->isEquipped(gift))
            {
                owner->unequip(gift, 1);
            }
        }
        else
        {
            gift = clone_object(effects["give"]);
        }
        tell_room(environment(owner), sprintf("%s gives %s to %s.\n",
            owner->Name(), gift->query("name"), actor->Name()));
        move_object(gift, actor);
    }
    if (member(effects, "vanish"))
    {
        object *items = deep_inventory(owner);
        if (sizeof(items))
        {
            foreach(object item in items)
            {
                destruct(item);
            }
        }
        destruct(owner);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int displayResponse(string choice, object actor, object owner)
{
    int ret = 0;
    if (objectp(owner) && member(responseKeys, choice))
    {
        ret = 1;
        string key = responseKeys[choice];
        string id = regexplode(key, "#")[0];

        displayMessage("\n" + topics[id]["responses"][key]["template"] + 
            "\n\n", actor, owner);

        if (member(topics[id]["responses"][key], "topic"))
        {
            owner->responseFromConversation(actor,
                topics[id]["responses"][key]["topic"]);
        }
        else
        {
            owner->responseFromConversation(actor, "default");
        }

        if (member(topics[id]["responses"][key], "event"))
        {
            owner->notifySynchronous(topics[id]["responses"][key]["event"], actor);
        }
        if (member(topics[id]["responses"][key], "effect"))
        {
            executeResponseEffect(topics[id]["responses"][key]["effect"],
                actor, owner);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void displayResponses(string id, object actor, object owner)
{
    if (member(topics, id) && member(topics[id], "responses"))
    {
        responseKeys = ([]);
        string *responses = sort_array(m_indices(topics[id]["responses"]),
            (: $1 > $2 :));
        foreach(string response in responses)
        {
            if (checkPrerequisites(actor, response, owner))
            {
                string choice = to_string(sizeof(responseKeys) + 1);
                responseKeys[choice] = id + "#" + 
                    topics[id]["responses"][response]["selection"];

                string message = topics[id]["responses"][response]["selection"];
                message = regreplace(message, "@A@((.+))@E@", Stat("\\1"), 1);
                message = regreplace(message, "@I@(.+)@E@", Action("\\1"), 1);

                tell_object(actor, format(Action(choice) + ": " +
                    Speech + message + End, 78));
            }
        }
    }
    ignoreTalk = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *responses()
{
    return m_indices(responseKeys) + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int speakMessage(string key, object actor, object owner)
{
    int ret = 0;

    if (actor && mappingp(topics[key]) &&
        member(topics[key], "template") &&
        checkPrerequisites(actor, key, owner))
    {
        displayMessage(topics[key]["template"], actor, owner);

        if (member(topics[key], "responses"))
        {
            displayResponses(key, actor, owner);
        }
        else if(!member(topics[key], "is repeatable"))
        {
            owner->responseFromConversation(actor, "default");
        }
        if (member(topics[key], "event"))
        {
            owner->notifySynchronous(topics[key]["event"], actor);
        }
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void triggerConversation(string trigger,
    object actor, object owner)
{
    ignoreTalk = 0;

    string *topicList = m_indices(topics);
    if (sizeof(topicList))
    {
        foreach(string topic in topicList)
        {
            if (member(topics[topic], "trigger") &&
                (topics[topic]["trigger"] == trigger))
            {
                speakMessage(topic, actor, owner);
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void registerConversationEvents(object owner)
{
    string *topicList = filter(m_indices(topics), 
        (: member(topics[$1], "event") :));

    if (sizeof(topicList))
    {
        foreach(string topic in topicList)
        {
            owner->registerEventHandler(topics[topic]["event"]);
        }
    }
}
