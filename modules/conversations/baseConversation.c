//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";

protected object Configuration = 
    load_object("/lib/dictionaries/configurationDictionary.c");

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
protected nomask void addConditionalTopicAddendum(string id, string addendumID,
    mapping prerequisite, string template)
{
    if (member(topics, id) && mappingp(prerequisite))
    {
        if (!member(topics[id], "addendum"))
        {
            topics[id]["addendum"] = ([]);
        }

        topics[id]["addendum"][addendumID] = template;
        foreach(string key in m_indices(prerequisite))
        {
            if (!addPrerequisite(key, prerequisite[key], addendumID))
            {
                raise_error(sprintf("ERROR - baseConversation.c, "
                    "addConditionalTopicAddendum:"
                    " The passed prerequisite to '%s' is invalid.\n", id));
            }
        }
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, "
            "addConditionalTopicAddendum:"
            " Could not add the addendum to '%s'. Make sure that "
            "the topic exists.\n", id));
    }
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
    if (member(topics, id) && mappingp(prerequisite))
    {
        foreach(string key in m_indices(prerequisite))
        {
            if (!addPrerequisite(key, prerequisite[key], id))
            {
                raise_error(sprintf("ERROR - baseConversation.c, addTopicPrerequisite:"
                    " The passed prerequisite to '%s' is invalid.\n", id));
            }
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
protected nomask varargs void addTopicInterjection(string id, string actor,
    string actorTopic, int ignoreDependency)
{
    if (member(topics, id))
    {
        if (file_size(actor) > 0)
        {
            object actorObj = load_object(actor);
            if ((actorObj && actorObj->hasTopic(actorTopic)) || ignoreDependency)
            {
                topics[id]["interjection"] = ([ 
                    "actor": actor,
                    "topic": actorTopic
                ]);
            }
            else if(!ignoreDependency)
            {
                raise_error(sprintf("ERROR - baseConversation.c, addTopicInterjection: "
                    "Topic '%s' does not exist on actor.\n", actorTopic));
            }
        }
        else
        {
            raise_error(sprintf("ERROR - baseConversation.c, addTopicInterjection: "
                "Actor '%s' does not exist.\n", actor));
        }
    }
    else
    {
        raise_error(sprintf("ERROR - baseConversation.c, addTopicInterjection: "
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
protected nomask varargs void addResponsePrerequisite(string id, string selection, 
    mapping prerequisite, int alwaysShow)
{
    string response = sprintf("%s#%s", id, selection);

    if (member(topics, id) && member(topics[id], "responses") &&
        member(topics[id]["responses"], response) &&
        (mappingp(prerequisite)))
    {
        if (alwaysShow)
        {
            topics[id]["responses"][response]["always show"] = 1;
        }

        foreach(string key in m_indices(prerequisite))
        {
            if (!addPrerequisite(key, prerequisite[key], response))
            {
                raise_error(sprintf("ERROR - baseConversation.c, addResponsePrerequisite:"
                    " The passed prerequisite to '%s' is invalid.\n", selection));
            }
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
    string *validEffects = ({ "opinion", "attack", "move", "give", "vanish",
        "experience" });
    string *effects = m_indices(effectMap);
    if (sizeof(effects))
    {
        ret = 1;
        foreach(string effect in effects)
        {
            ret &&= member(validEffects, effect) > -1;

            switch (effect)
            {
                case "experience":
                {
                    ret &&= (intp(effectMap[effect]) ||
                        (mappingp(effectMap[effect]) &&
                            member(effectMap[effect], "amount") &&
                            member(effectMap[effect], "guild")));
                    break;
                }
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
    object initiator, object target, string colorConfiguration)
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
    message = regreplace(message, "@S@([^@\x1b]*)", 
        Configuration->decorate("\\1", "speech", "conversation", 
            colorConfiguration), 1);

    message = regreplace(message, "@D@([^@\x1b]*)",
        Configuration->decorate("\\1", "description", "conversation",
            colorConfiguration), 1);

    message = regreplace(message, "@A@((.+))@E@",
        Configuration->decorate("[\\1]", "condition", "conversation",
            colorConfiguration), 1);

    message = regreplace(message, "@I@(.+)@E@",
        Configuration->decorate("[\\1]", "action", "conversation",
            colorConfiguration), 1);

    message = regreplace(message, "@H@(.+)@E@",
        Configuration->decorate("\\1", "highlight", "conversation",
            colorConfiguration), 1);
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
        object *characters = filter(all_inventory(environment(initiator)),
            (: $1->isRealizationOfLiving() :));

        foreach(object person in characters)
        {
            if (person && objectp(person))// && interactive(person))
            {
                string colorConfiguration = person->colorConfiguration() ?
                    person->colorConfiguration() : "3-bit";

                string parsedMessage;
                if (person == initiator)
                {
                    parsedMessage = parseTemplate(message, "initiator", initiator,
                        target, colorConfiguration);
                }
                else if (person == target)
                {
                    parsedMessage = parseTemplate(message, "target",
                        initiator, target, colorConfiguration);
                }
                else
                {
                    parsedMessage = parseTemplate(message, "other",
                        initiator, target, colorConfiguration);
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
    if (member(effects, "experience"))
    {
        string colorConfiguration = actor->colorConfiguration();

        if (mappingp(effects["experience"]) && 
            actor->memberOfGuild(effects["experience"]["guild"]))
        {
            actor->addExperience(effects["experience"]["amount"],
                effects["experience"]["guild"]);
            tell_object(actor, Configuration->decorate(
                sprintf("You have gained %d experience (%s only).\n",
                    effects["experience"]["amount"],
                    effects["experience"]["guild"]), "level up", "score",
                colorConfiguration));
        }
        else
        {
            actor->addExperience(effects["experience"]);
            tell_object(actor, Configuration->decorate(
                sprintf("You have gained %d experience.\n", 
                    effects["experience"]), "level up", "score", 
                colorConfiguration));
        }
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
        responseKeys = ([]);

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

        int elements = 0;
        foreach(string response in responses)
        {
            int disabled = member(topics[id]["responses"][response], 
                "always show") && 
                !checkPrerequisites(actor, response, owner);

            if (checkPrerequisites(actor, response, owner) || disabled)
            {
                elements++;
                string choice = to_string(elements);
                if (!disabled)
                {
                    responseKeys[choice] = id + "#" +
                        topics[id]["responses"][response]["selection"];
                }

                string message = topics[id]["responses"][response]["selection"];
                
                string colorConfiguration = actor->colorConfiguration();

                message = regreplace(message, "@A@((.+))@E@",
                    Configuration->decorate("[\\1]", 
                        disabled ? "disabled" : "condition", "conversation",
                        colorConfiguration), 1);
                message = regreplace(message, "@I@(.+)@E@",
                    Configuration->decorate("[\\1]", 
                        disabled ? "disabled" : "action", "conversation",
                        colorConfiguration), 1);

                tell_object(actor,
                    Configuration->decorate(sprintf("[%s]: ", choice),
                        disabled ? "disabled" : "action", "conversation", 
                        colorConfiguration) +
                    Configuration->decorate(format(message, 72),
                        disabled ? "disabled" : "speech", "conversation", 
                        colorConfiguration));
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
private nomask string getTopicTemplate(string key, object actor, object owner)
{
    string ret = topics[key]["template"];

    if (member(topics[key], "addendum"))
    {
        string *addenda = m_indices(topics[key]["addendum"]);
        if (sizeof(addenda))
        {
            foreach(string addendum in addenda)
            {
                if (checkPrerequisites(actor, addendum, owner))
                {
                    ret += topics[key]["addendum"][addendum];
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int speakMessage(string key, object actor, object owner)
{
    int ret = 0;

    if (actor && mappingp(topics[key]) &&
        member(topics[key], "template") &&
        checkPrerequisites(actor, key, owner))
    {
        displayMessage("\n" + getTopicTemplate(key, actor, owner), actor, owner);

        if (member(topics[key], "interjection") && environment(owner))
        {
            object interloper = present_clone(
                topics[key]["interjection"]["actor"],
                environment(owner));

            if (objectp(interloper))
            {
                interloper->onTriggerConversation(actor,
                    topics[key]["interjection"]["topic"]);
            }
        }

        if (member(topics[key], "responses"))
        {
            displayResponses(key, actor, owner);
        }
        else if(owner && !member(topics[key], "is repeatable"))
        {
            owner->responseFromConversation(actor, "default");
        }
        if (owner && member(topics[key], "event"))
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
