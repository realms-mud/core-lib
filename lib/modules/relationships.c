//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/relationships.h"

private mapping relationshipInteractions = ([]);
private string RelationshipIdentity;
private nomask int isPersistentRelationshipActor(mixed actor);

/////////////////////////////////////////////////////////////////////////////
public nomask string relationshipIdentity()
{
    string ret = "";
    if (isPersistentRelationshipActor(this_object()) &&
        this_object()->Name())
    {
        ret = sprintf("/lib/realizations/player.c#%s", this_object()->Name());
    }
    else if (!RelationshipIdentity && function_exists("Name", this_object()) &&
        this_object()->Name())
    {
        RelationshipIdentity = sprintf("%s#%s",
            program_name(this_object()),
            this_object()->Name());
    }
    if (ret == "")
    {
        ret = RelationshipIdentity ? RelationshipIdentity : "";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int isPersistentRelationshipActor(mixed actor)
{
    return objectp(actor) &&
        function_exists("isRealizationOfPlayer", actor) &&
        actor->isRealizationOfPlayer();
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping updateRecord(mapping store, mixed source, mixed target,
    mapping changes)
{
    object service = getService("relationship");
    string key = service->identity(target);
    string sourceKey = service->identity(source);
    if (source != this_object())
    {
        key = sourceKey;
    }
    mapping ret = ([]);
    if (key == "" || sourceKey == "" ||
        sourceKey == service->identity(target) ||
        !service->validChanges(changes))
    {
        raise_error("ERROR - relationships: Invalid relationship change.\n");
    }
    else
    {
        mapping values = member(store, key) ?
            store[key]["dimensions"] : ([]);
        ret = ([
            "source":sourceKey,
            "target":service->identity(target),
            "dimensions":service->applyChanges(values, changes),
            "updated":time(),
            "revision":member(store, key) ? store[key]["revision"] + 1 : 1
        ]);
        store[key] = ret;
        m_delete(derivedRelationships, sourceKey + "->" +
            service->identity(target));
        ret = cloneRelationshipEntry(ret);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping updateRelationshipFrom(mixed source,
    mapping changes, mapping context, mapping metadata, mixed producer)
{
    mapping ret = ([]);
    if (objectp(source) && isPersistentRelationshipActor(source))
    {
        ret = source->updateRelationshipToward(this_object(), changes,
            context, metadata, producer);
    }
    else
    {
        if (!isPersistentRelationshipActor(this_object()))
        {
            ret = load_object(
                "/lib/modules/secure/dataServices/relationshipsDataService.c"
                )->changeWorldRelationship(
                    getService("relationship")->identity(source),
                    relationshipIdentity(), changes);
        }
        else
        {
            ret = updateRecord(incomingRelationships, source, this_object(),
                changes);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping updateRelationshipToward(mixed target,
    mapping changes, mapping context, mapping metadata, mixed producer)
{
    mapping ret = ([]);
    if (!isPersistentRelationshipActor(this_object()) &&
        isPersistentRelationshipActor(target))
    {
        ret = target->updateRelationshipFrom(this_object(), changes,
            context, metadata, producer);
    }
    else
    {
        if (!isPersistentRelationshipActor(this_object()))
        {
            ret = load_object(
                "/lib/modules/secure/dataServices/relationshipsDataService.c"
                )->changeWorldRelationship(relationshipIdentity(),
                    getService("relationship")->identity(target), changes);
        }
        else
        {
            ret = updateRecord(relationships, this_object(), target, changes);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipToward(mixed target)
{
    mapping ret = ([]);
    if (!isPersistentRelationshipActor(this_object()) &&
        isPersistentRelationshipActor(target))
    {
        ret = target->relationshipFrom(this_object());
    }
    else
    {
        string key = getService("relationship")->identity(target);
        if (!isPersistentRelationshipActor(this_object()) &&
            key != "" && relationshipIdentity() != "")
        {
            mapping *records = load_object(
                "/lib/modules/secure/dataServices/relationshipsDataService.c"
                )->worldRelationships(relationshipIdentity(), key);
            if (sizeof(records))
            {
                ret = records[0];
            }
        }
        else if (member(relationships, key))
        {
            ret = cloneRelationshipEntry(relationships[key]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipFrom(mixed source)
{
    mapping ret = ([]);
    if (objectp(source) && isPersistentRelationshipActor(source))
    {
        ret = source->relationshipToward(this_object());
    }
    else
    {
        string key = getService("relationship")->identity(source);
        if (!isPersistentRelationshipActor(this_object()) &&
            key != "" && relationshipIdentity() != "")
        {
            mapping *records = load_object(
                "/lib/modules/secure/dataServices/relationshipsDataService.c"
                )->worldRelationships(key, relationshipIdentity());
            if (sizeof(records))
            {
                ret = records[0];
            }
        }
        else if (member(incomingRelationships, key))
        {
            ret = cloneRelationshipEntry(incomingRelationships[key]);
        }
        else if (objectp(source) &&
            !isPersistentRelationshipActor(this_object()))
        {
            ret = source->relationshipToward(this_object());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int relationshipDimensionToward(mixed target, string dimension)
{
    int ret = 0;
    if (!getService("relationship")->isValidDimension(dimension))
    {
        raise_error("ERROR - relationships: Invalid dimension.\n");
    }
    else
    {
        mapping record = relationshipToward(target);
        if (sizeof(record))
        {
            ret = record["dimensions"][dimension];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasRelationshipToward(mixed target)
{
    return sizeof(relationshipToward(target)) > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int relationshipValue(mixed target, string dimension)
{
    return relationshipDimensionToward(target, dimension);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipWith(mixed target)
{
    return relationshipToward(target);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipData(mixed target)
{
    return relationshipToward(target);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasRelationship(mixed target)
{
    return hasRelationshipToward(target);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *relationshipDimensions()
{
    return getService("relationship")->relationshipDimensions();
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping modifyRelationship(mixed target,
    string dimension, int amount, mapping context)
{
    return updateRelationshipToward(target, ([ dimension:amount ]),
        context, ([]), "relationship.modify");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping setRelationshipValue(mixed target,
    string dimension, int value)
{
    int normalized = getService("relationship")->normalizeValue(
        dimension, value);
    return modifyRelationship(target, dimension,
        normalized - relationshipDimensionToward(target, dimension));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string relationshipType(mixed target)
{
    return getService("relationship")->relationshipType(this_object(), target);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping relationshipSummary(mixed target,
    string direction)
{
    mapping record = direction == "from" ?
        relationshipFrom(target) : relationshipToward(target);
    string other = getService("relationship")->identity(target);
    string key = direction == "from" ?
        other + "->" + relationshipIdentity() :
        relationshipIdentity() + "->" + other;
    int revision = sizeof(record) ? record["revision"] : -1;
    mapping values = sizeof(record) ? record["dimensions"] : ([]);
    int changed = !member(derivedRelationships, key) ||
        derivedRelationships[key]["revision"] != revision;
    if (!changed)
    {
        mapping previous = derivedRelationships[key]["dimensions"];
        changed = sizeof(previous) != sizeof(values);
        foreach(string dimension in m_indices(values))
        {
            changed ||= !member(previous, dimension) ||
                previous[dimension] != values[dimension];
        }
    }
    if (changed)
    {
        derivedRelationships[key] = ([
            "revision":revision,
            "dimensions":values + ([]),
            "summary":getService("relationship")->deriveRelationship(record)
        ]);
    }
    return derivedRelationships[key]["summary"] + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *queryRelationships(mapping query)
{
    mapping *ret = ({ });
    if (mappingp(query) && member(query, "target"))
    {
        mapping record = relationshipToward(query["target"]);
        if (sizeof(record) &&
            getService("relationship")->matchesQuery(record, query))
        {
            ret += ({ record });
        }
    }
    else
    {
        mapping *records = isPersistentRelationshipActor(this_object()) ?
            m_values(relationships) : load_object(
                "/lib/modules/secure/dataServices/relationshipsDataService.c"
                )->worldRelationships(relationshipIdentity(), "");
        foreach(mapping record in records)
        {
            if (getService("relationship")->matchesQuery(record, query))
            {
                ret += ({ cloneRelationshipEntry(record) });
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addRelationshipInteraction(string interaction,
    mapping changes)
{
    if (!stringp(interaction) || interaction == "" ||
        !getService("relationship")->validChanges(changes))
    {
        raise_error("ERROR - relationships: Invalid authored interaction.\n");
    }
    else
    {
        relationshipInteractions[interaction] = changes + ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipInteractionChanges(string interaction)
{
    return member(relationshipInteractions, interaction) ?
        relationshipInteractions[interaction] + ([]) :
        getService("relationship")->defaultInteractionChanges(interaction);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int relationshipInteraction(object actor,
    string interaction, mapping context)
{
    int ret = 0;
    mapping changes = relationshipInteractionChanges(interaction);
    if (sizeof(changes))
    {
        updateRelationshipToward(actor, changes,
            context, ([]), interaction);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping recordRelationshipInteraction(mixed target,
    string type, mapping changes, mapping context, string direction)
{
    mapping ret = ([]);
    if (!stringp(type) || type == "" ||
        !function_exists("recordObservation", this_object()) ||
        (direction && direction != "toward" && direction != "from"))
    {
        raise_error("ERROR - relationships: Invalid semantic interaction.\n");
    }
    else
    {
        ret = direction == "from" ?
            updateRelationshipFrom(target, changes, context, ([]), type) :
            updateRelationshipToward(target, changes, context, ([]), type);
        mapping observation = this_object()->recordObservation(([
            "type":type,
            "subject":target,
            "context":mappingp(context) ? context : ([]),
            "metadata":([
                "relationship source":ret["source"],
                "relationship target":ret["target"],
                "relationship changes":changes + ([])
            ])
        ]));
        if (!mappingp(observation))
        {
            raise_error("ERROR - relationships: Could not record "
                "the interaction observation.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *relationshipHistoryToward(mixed target, mapping query)
{
    mapping *ret = ({ });
    string key = getService("relationship")->identity(target);
    if (member(relationshipHistory, key))
    {
        foreach(mapping entry in relationshipHistory[key])
        {
            int matches = 1;
            foreach(string field in m_indices(query))
            {
                matches &&= member(entry, field) && entry[field] == query[field];
            }
            if (matches)
            {
                ret += ({ cloneHistoryEntry(entry) });
            }
        }
    }
    return ret;
}
