//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

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
    ret["ID"] = (member(ret, "ID") &&
        stringp(ret["ID"]) && (ret["ID"] != "")) ?
        ret["ID"] : generateGuid();
    ret["actor"] = actorKey(ret["actor"]);
    ret["subject"] = member(ret, "subject") ? sanitizeValue(ret["subject"]) : "";
    ret["participants"] = (member(ret, "participants") && pointerp(ret["participants"])) ?
        sanitizeValue(ret["participants"]) : ({ });
    ret["timestamp"] = (member(ret, "timestamp") && intp(ret["timestamp"])) ?
        ret["timestamp"] : time();
    ret["location"] = member(ret, "location") ?
        (objectp(observation["location"]) ?
            program_name(observation["location"]) : ret["location"]) :
        actorLocation(observation["actor"]);
    ret["context"] = (member(ret, "context") && mappingp(ret["context"])) ?
        sanitizeValue(ret["context"]) : ([]);
    ret["metadata"] = (member(ret, "metadata") && mappingp(ret["metadata"])) ?
        sanitizeValue(ret["metadata"]) : ([]);

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
            if (key == "time window")
            {
                mixed window = query[key];
                mixed minutes = mappingp(observation["context"]) ?
                    observation["context"]["minutes after midnight"] : 0;
                ret = mappingp(window) && sizeof(window) == 2 &&
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
            }
            else if (key == "since" || key == "until")
            {
                ret = intp(query[key]) && query[key] >= 0 &&
                    member(observation, "timestamp") &&
                    intp(observation["timestamp"]) &&
                    ((key == "since") ?
                        observation["timestamp"] >= query[key] :
                        observation["timestamp"] <= query[key]);
            }
            else if (key == "type")
            {
                ret = typeMatches(query[key], observation["type"]);
            }
            else if (member(observation, key))
            {
                ret = valueMatches(query[key], observation[key]);
            }
            else if (mappingp(observation["context"]) &&
                member(observation["context"], key))
            {
                ret = valueMatches(query[key], observation["context"][key]);
            }
            else if (mappingp(observation["metadata"]) &&
                member(observation["metadata"], key))
            {
                ret = valueMatches(query[key], observation["metadata"][key]);
            }
            else
            {
                ret = 0;
            }

            if (!ret)
            {
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
        if (objectp(actor))
        {
            if (function_exists("Race", actor))
            {
                ret["race"] = actor->Race();
            }
            if (function_exists("memberOfGuilds", actor))
            {
                ret["guilds"] = actor->memberOfGuilds();
            }
            if (function_exists("Factions", actor))
            {
                ret["factions"] = actor->Factions();
            }
            if (detailed && function_exists("isEquipped", actor) &&
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
                ret["equipment"] = equipment;
            }
            if (detailed &&
                function_exists("activeSustainedResearch", actor))
            {
                ret["active research"] = actor->activeSustainedResearch();
            }
            if (detailed && function_exists("Traits", actor))
            {
                ret["effects"] = actor->Traits("effect") +
                    actor->Traits("sustained effect");
            }
        }
        if (objectp(room))
        {
            if (function_exists("getRegion", room))
            {
                object region = room->getRegion();
                if (objectp(region))
                {
                    ret["region"] = program_name(region);
                    ret["region name"] = region->regionName();
                }
            }
            if (function_exists("currentState", room))
            {
                ret["environment state"] = room->currentState();
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
                        ret["state"] = state;
                    }
                }
            }
        }
        if (typeMatches("combat", observation["type"]))
        {
            object subject = observation["subject"];
            if (objectp(subject))
            {
                ret["target identity"] = actorKey(subject);
                if (function_exists("Name", subject))
                {
                    ret["target name"] = subject->Name();
                }
                if (function_exists("Race", subject))
                {
                    ret["target race"] = subject->Race();
                }
                if (function_exists("effectiveLevel", subject))
                {
                    ret["target level"] = subject->effectiveLevel();
                }
            }
            if (objectp(actor) &&
                function_exists("equipmentInSlot", actor))
            {
                object weapon = actor->equipmentInSlot("wielded primary");
                if (objectp(weapon))
                {
                    ret["weapon identity"] = actorKey(weapon);
                    ret["weapon"] = weapon->query("blueprint");
                }
            }
        }
        object calendar = getService("environment");
        if (objectp(calendar))
        {
            ret["season"] = calendar->season();
            ret["moon phase"] = calendar->moonPhase();
            ret["time of day"] = calendar->timeOfDay();
            ret["minutes after midnight"] = calendar->currentTime();
            ret["day"] = calendar->currentDay();
            ret["year"] = calendar->currentYear();
        }
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

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *queryObservations(mapping *observations, mapping query)
{
    mapping *ret = ({ });
    mapping criteria = mappingp(query) ? sanitizeValue(query) : 0;

    if (pointerp(observations))
    {
        foreach(mixed item in observations)
        {
            if (mappingp(item) && observationMatches(item, criteria))
            {
                ret += ({ cloneObservation(item) });
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int countObservations(mapping *observations, mapping query)
{
    int ret = 0;
    mapping criteria = mappingp(query) ? sanitizeValue(query) : 0;

    if (pointerp(observations))
    {
        foreach(mixed observation in observations)
        {
            if (mappingp(observation) &&
                observationMatches(observation, criteria))
            {
                ret++;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasObservation(mapping *observations, mapping query)
{
    int ret = 0;
    mapping criteria = mappingp(query) ? sanitizeValue(query) : 0;

    if (pointerp(observations))
    {
        foreach(mixed observation in observations)
        {
            if (mappingp(observation) &&
                observationMatches(observation, criteria))
            {
                ret = 1;
                break;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping summarizeObservations(mapping *observations)
{
    mapping ret = ([
        "total": sizeof(observations),
        "by type": ([]),
        "by subject": ([]),
        "by location": ([]),
        "context": ([]),
        "metadata": ([])
    ]);

    foreach(mapping observation in observations)
    {
        foreach(string field in ({ "type", "subject", "location" }))
        {
            ret["by " + field][observation[field]]++;
        }
        foreach(string field in ({ "context", "metadata" }))
        {
            foreach(string key in m_indices(observation[field]))
            {
                if (!member(ret[field], key))
                {
                    ret[field][key] = ([]);
                }
                mixed value = observation[field][key];
                string countKey = stringp(value) ? value :
                    sprintf("%O", value);
                ret[field][key][countKey]++;
            }
        }
    }
    return ret;
}