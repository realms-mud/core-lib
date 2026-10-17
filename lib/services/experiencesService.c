//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object observationDatabase;
private nomask mixed sanitizeValue(mixed value);

/////////////////////////////////////////////////////////////////////////////
private object database()
{
    if (!observationDatabase)
    {
        observationDatabase = clone_object(
            "/lib/modules/secure/dataServices/experiencesDataService.c");
    }
    return observationDatabase;
}

/////////////////////////////////////////////////////////////////////////////
public void storeObservation(int playerId, mapping observation)
{
    database()->storeObservation(playerId, observation);
}

/////////////////////////////////////////////////////////////////////////////
public mapping *queryPlayerObservations(int playerId, mapping criteria,
    int limit, int offset)
{
    return database()->queryPlayerObservations(playerId,
        sanitizeValue(criteria), limit, offset);
}

/////////////////////////////////////////////////////////////////////////////
public int countPlayerObservations(int playerId, mapping criteria)
{
    return database()->countPlayerObservations(playerId,
        sanitizeValue(criteria), 0);
}

/////////////////////////////////////////////////////////////////////////////
public int hasPlayerObservation(int playerId, mapping criteria, int minimum)
{
    return database()->countPlayerObservations(playerId,
        sanitizeValue(criteria), minimum) >= minimum;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string actorKey(mixed actor)
{
    string ret = "";

    if (objectp(actor))
    {
        string actorName = function_exists("Name", actor) &&
            actor->Name() ? actor->Name() : "any";
        ret = sprintf("%s#%s", program_name(actor), actorName);
    }
    else if (stringp(actor))
    {
        ret = actor;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string actorLocation(mixed actor)
{
    string ret = "";

    if (objectp(actor) && objectp(environment(actor)))
    {
        ret = program_name(environment(actor));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string actorStorageKey(mixed actor)
{
    string ret = actorKey(actor);
    string actorPath = "";
    string actorName = "";

    if (sscanf(ret, "%s#%s", actorPath, actorName) == 2)
    {
        if ((sizeof(actorPath) > 2) && (actorPath[(sizeof(actorPath) - 2)..] == ".c"))
        {
            actorPath = actorPath[0..(sizeof(actorPath) - 3)];
        }
        ret = sprintf("%s#%s", actorPath, lower_case(actorName));
    }

    return lower_case(ret);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed sanitizeValue(mixed value)
{
    mixed ret = value;

    if (objectp(value))
    {
        ret = actorKey(value);
    }
    else if (pointerp(value))
    {
        ret = ({ });

        foreach(mixed item in value)
        {
            ret += ({ sanitizeValue(item) });
        }
    }
    else if (mappingp(value))
    {
        ret = ([]);

        foreach(mixed key in m_indices(value))
        {
            ret[key] = sanitizeValue(value[key]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneObservation(mapping observation)
{
    return sanitizeValue(observation);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidObservation(mapping observation)
{
    return mappingp(observation) &&
        member(observation, "type") &&
        member(observation, "actor") &&
        stringp(observation["type"]) &&
        (observation["type"] != "") &&
        (actorStorageKey(observation["actor"]) != "") &&
        (!member(observation, "subject") ||
            objectp(observation["subject"]) ||
            stringp(observation["subject"])) &&
        (!member(observation, "participants") ||
            pointerp(observation["participants"])) &&
        (!member(observation, "timestamp") ||
            (intp(observation["timestamp"]) &&
                observation["timestamp"] >= 0)) &&
        (!member(observation, "location") ||
            objectp(observation["location"]) ||
            stringp(observation["location"])) &&
        (!member(observation, "context") ||
            mappingp(observation["context"])) &&
        (!member(observation, "metadata") ||
            mappingp(observation["metadata"]));
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping enrichObservation(mapping observation)
{
    mapping ret = cloneObservation(observation);

    ret["type"] = lower_case(ret["type"]);
    ret["actor"] = actorKey(ret["actor"]);
    ret["subject"] = member(ret, "subject") ? ret["subject"] : "";
    ret["participants"] = (member(ret, "participants") && pointerp(ret["participants"])) ?
        ret["participants"] : ({ });
    ret["timestamp"] = (member(ret, "timestamp") && intp(ret["timestamp"])) ?
        ret["timestamp"] : time();
    ret["location"] = member(ret, "location") ?
        (objectp(observation["location"]) ?
            program_name(observation["location"]) : ret["location"]) :
        actorLocation(observation["actor"]);
    ret["context"] = (member(ret, "context") && mappingp(ret["context"])) ?
        ret["context"] : ([]);
    ret["metadata"] = (member(ret, "metadata") && mappingp(ret["metadata"])) ?
        ret["metadata"] : ([]);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int typeMatches(string queryType, string observedType)
{
    int ret = 0;

    if (stringp(queryType) && stringp(observedType) && (queryType != ""))
    {
        queryType = lower_case(queryType);
        observedType = lower_case(observedType);

        ret = (queryType == observedType) ||
            ((sizeof(observedType) > sizeof(queryType)) &&
            (observedType[0..(sizeof(queryType) - 1)] == queryType) &&
            (observedType[sizeof(queryType)] == '.'));
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int valueMatches(mixed expected, mixed actual)
{
    int ret = 0;

    if (mappingp(expected) && mappingp(actual))
    {
        ret = 1;
        foreach(mixed key in m_indices(expected))
        {
            if (!member(actual, key) || !valueMatches(expected[key], actual[key]))
            {
                ret = 0;
                break;
            }
        }
    }
    else if (pointerp(expected) && pointerp(actual))
    {
        ret = 1;
        foreach(mixed value in expected)
        {
            if (member(actual, value) < 0)
            {
                ret = 0;
                break;
            }
        }
    }
    else if (stringp(expected) && stringp(actual))
    {
        ret = (lower_case(expected) == lower_case(actual));
    }
    else
    {
        ret = (expected == actual);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int timeWindowMatches(mapping observation, mixed window)
{
    mixed minutes = mappingp(observation["context"]) ?
        observation["context"]["minutes after midnight"] : 0;
    int ret = mappingp(window) && sizeof(window) == 2 &&
        member(window, "center") && member(window, "minutes") &&
        (intp(window["center"]) || floatp(window["center"])) &&
        (intp(window["minutes"]) || floatp(window["minutes"])) &&
        window["center"] >= 0 && window["center"] < 1440 &&
        window["minutes"] >= 0 && window["minutes"] <= 720 &&
        mappingp(observation["context"]) &&
        member(observation["context"], "minutes after midnight") &&
        (intp(minutes) || floatp(minutes)) &&
        minutes >= 0 && minutes < 1440;

    if (ret)
    {
        mixed distance = abs(minutes - window["center"]);
        ret = distance <= window["minutes"] ||
            1440 - distance <= window["minutes"];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int timestampMatches(mapping observation, string key,
    mixed boundary)
{
    return intp(boundary) && boundary >= 0 &&
        member(observation, "timestamp") &&
        intp(observation["timestamp"]) &&
        ((key == "since") ? observation["timestamp"] >= boundary :
            observation["timestamp"] <= boundary);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int observationFieldMatches(mapping observation, mixed key,
    mixed expected)
{
    int ret = 0;

    if (key == "time window")
    {
        ret = timeWindowMatches(observation, expected);
    }
    else if (key == "since" || key == "until")
    {
        ret = timestampMatches(observation, key, expected);
    }
    else if (key == "type")
    {
        ret = typeMatches(expected, observation["type"]);
    }
    else if (member(observation, key))
    {
        ret = valueMatches(expected, observation[key]);
    }
    else if (mappingp(observation["context"]) &&
        member(observation["context"], key))
    {
        ret = valueMatches(expected, observation["context"][key]);
    }
    else if (mappingp(observation["metadata"]) &&
        member(observation["metadata"], key))
    {
        ret = valueMatches(expected, observation["metadata"][key]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int observationMatches(mapping observation, mapping query)
{
    int ret = mappingp(query);
    if (ret && member(query, "since") && member(query, "until"))
    {
        ret = intp(query["since"]) && intp(query["until"]) &&
            query["since"] <= query["until"];
    }

    if (ret)
    {
        foreach(mixed key in m_indices(query))
        {
            if (!observationFieldMatches(observation, key, query[key]))
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping normalizeObservation(mapping observation)
{
    mapping ret = 0;

    if (isValidObservation(observation))
    {
        ret = enrichObservation(observation);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addEquipmentContext(mapping context, object actor)
{
    if (function_exists("isEquipped", actor) &&
        function_exists("registeredInventoryObjects", actor))
    {
        mapping *equipment = ({ });
        object *items = actor->registeredInventoryObjects();
        if (pointerp(items))
        {
            foreach(object item in items)
            {
                if (objectp(item) && actor->isEquipped(item))
                {
                    equipment += ({ ([
                        "identity": actorKey(item),
                        "blueprint": item->query("blueprint"),
                        "locations": item->query("equipment locations"),
                        "materials": sanitizeValue(
                            item->query("crafting materials")),
                        "craftsmanship": item->query("craftsmanship")
                    ]) });
                }
            }
        }
        context["equipment"] = equipment;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addActorContext(mapping context, object actor,
    int detailed)
{
    if (objectp(actor))
    {
        if (function_exists("Race", actor))
        {
            context["race"] = actor->Race();
        }
        if (function_exists("memberOfGuilds", actor))
        {
            context["guilds"] = actor->memberOfGuilds();
        }
        if (function_exists("Factions", actor))
        {
            context["factions"] = actor->Factions();
        }
        if (detailed)
        {
            addEquipmentContext(context, actor);
            if (function_exists("activeSustainedResearch", actor))
            {
                context["active research"] = actor->activeSustainedResearch();
            }
            if (function_exists("Traits", actor))
            {
                context["effects"] = actor->Traits("effect") +
                    actor->Traits("sustained effect");
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRoomContext(mapping context, object actor, object room)
{
    if (objectp(room))
    {
        if (function_exists("getRegion", room))
        {
            object region = room->getRegion();
            if (objectp(region))
            {
                context["region"] = program_name(region);
                context["region name"] = region->regionName();
            }
        }
        if (function_exists("currentState", room))
        {
            context["environment state"] = room->currentState();
        }
        if (objectp(actor) && function_exists("stateFor", actor) &&
            function_exists("stateMachine", room))
        {
            object machine = room->stateMachine();
            if (objectp(machine) && function_exists("Name", machine))
            {
                string state = actor->stateFor(machine);
                if (stringp(state))
                {
                    context["state"] = state;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addCombatContext(mapping context, object actor,
    mixed subject)
{
    if (objectp(subject))
    {
        context["target identity"] = actorKey(subject);
        if (function_exists("Name", subject))
        {
            context["target name"] = subject->Name();
        }
        if (function_exists("Race", subject))
        {
            context["target race"] = subject->Race();
        }
        if (function_exists("effectiveLevel", subject))
        {
            context["target level"] = subject->effectiveLevel();
        }
    }
    if (objectp(actor) && function_exists("equipmentInSlot", actor))
    {
        object weapon = actor->equipmentInSlot("wielded primary");
        if (objectp(weapon))
        {
            context["weapon identity"] = actorKey(weapon);
            context["weapon"] = weapon->query("blueprint");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addCalendarContext(mapping context)
{
    object calendar = getService("environment");
    if (objectp(calendar))
    {
        context["season"] = calendar->season();
        context["moon phase"] = calendar->moonPhase();
        context["time of day"] = calendar->timeOfDay();
        context["minutes after midnight"] = calendar->currentTime();
        context["day"] = calendar->currentDay();
        context["year"] = calendar->currentYear();
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping buildObservationContext(object actor,
    mapping observation)
{
    mapping ret = ([]);

    if (mappingp(observation))
    {
        int detailed = typeMatches("combat", observation["type"]) ||
            typeMatches("research", observation["type"]) ||
            typeMatches("craft", observation["type"]);
        object room = objectp(actor) ? environment(actor) : 0;
        if (objectp(observation["location"]))
        {
            room = observation["location"];
        }
        addActorContext(ret, actor, detailed);
        addRoomContext(ret, actor, room);
        if (typeMatches("combat", observation["type"]))
        {
            addCombatContext(ret, actor, observation["subject"]);
        }
        addCalendarContext(ret);
        if (mappingp(observation["context"]))
        {
            ret += sanitizeValue(observation["context"]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int matchesObservation(mapping observation, mapping criteria)
{
    return mappingp(observation) && mappingp(criteria) &&
        observationMatches(observation, sanitizeValue(criteria));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping recordObservation(object module,
    mapping observation)
{
    mapping ret = 0;

    if (objectp(module) && mappingp(observation) &&
        function_exists("recordObservation", module))
    {
        ret = module->recordObservation(observation);
    }

    return ret;
}
