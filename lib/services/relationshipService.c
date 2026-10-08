//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping dimensions = ([
    "trust":({ -100, 100 }),
    "respect":({ -100, 100 }),
    "affection":({ -100, 100 }),
    "gratitude":({ 0, 100 }),
    "fear":({ 0, 100 }),
    "suspicion":({ 0, 100 }),
    "rivalry":({ 0, 100 }),
    "admiration":({ 0, 100 }),
    "obligation":({ 0, 100 })
]);
public nomask string classify(mapping values);

/////////////////////////////////////////////////////////////////////////////
public nomask string identity(mixed actor)
{
    string ret = "";
    if (objectp(actor) && function_exists("Name", actor) && actor->Name())
    {
        ret = function_exists("relationshipIdentity", actor) ?
            actor->relationshipIdentity() :
            sprintf("%s#%s", program_name(actor), actor->Name());
    }
    else if (stringp(actor) && sizeof(actor) &&
        sizeof(explode(actor, "#")) == 2)
    {
        ret = actor;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidDimension(string dimension)
{
    return stringp(dimension) && member(dimensions, dimension);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *relationshipDimensions()
{
    return m_indices(dimensions);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int *dimensionBounds(string dimension)
{
    int *ret = ({ });
    if (isValidDimension(dimension))
    {
        ret = dimensions[dimension] + ({ });
    }
    else
    {
        raise_error("ERROR - relationship: Invalid dimension.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping defaultInteractionChanges(string interaction)
{
    mapping rules = ([
        "combat.protected":([ "trust":5, "respect":3, "gratitude":10 ]),
        "combat.rescue":([ "trust":10, "respect":5, "gratitude":20 ]),
        "combat.betrayal":([ "trust":-30, "respect":-15, "suspicion":20 ]),
        "trade.completed":([ "trust":2, "respect":1 ]),
        "training.completed":([ "respect":2, "admiration":1 ])
    ]);
    return member(rules, interaction) ? rules[interaction] + ([]) : ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping deriveRelationship(mapping record)
{
    mapping ret = ([
        "classification":sizeof(record) ?
            classify(record["dimensions"]) : "stranger",
        "strength":0,
        "dominant dimension":""
    ]);
    int greatest = 0;
    if (sizeof(record))
    {
        foreach(string dimension in sort_array(m_indices(dimensions),
            (: $1 > $2 :)))
        {
            int value = abs(record["dimensions"][dimension]);
            ret["strength"] += value;
            if (value > greatest)
            {
                greatest = value;
                ret["dominant dimension"] = dimension;
            }
        }
        ret["strength"] /= sizeof(dimensions);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validChanges(mixed changes)
{
    int ret = mappingp(changes) && sizeof(changes);
    if (ret)
    {
        foreach(mixed dimension in m_indices(changes))
        {
            ret &&= stringp(dimension) && isValidDimension(dimension) &&
                intp(changes[dimension]);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int normalizeValue(string dimension, int value)
{
    int ret = value;
    if (!isValidDimension(dimension))
    {
        raise_error("ERROR - relationship: Invalid dimension.\n");
    }
    else
    {
        ret = value < dimensions[dimension][0] ?
            dimensions[dimension][0] :
            (value > dimensions[dimension][1] ?
                dimensions[dimension][1] : value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping applyChanges(mapping current, mapping changes)
{
    mapping ret = current + ([]);
    if (!validChanges(changes))
    {
        raise_error("ERROR - relationship: Invalid dimension changes.\n");
    }
    else
    {
        foreach(string dimension in m_indices(changes))
        {
            int value = normalizeValue(dimension,
                member(ret, dimension) ? ret[dimension] : 0);
            int amount = changes[dimension];
            // Bound the delta before addition to avoid integer overflow.
            amount = amount > 200 ? 200 : (amount < -200 ? -200 : amount);
            ret[dimension] = normalizeValue(dimension, value + amount);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipToward(object source, mixed target)
{
    mapping ret = ([]);
    if (objectp(source) && function_exists("relationshipToward", source))
    {
        ret = source->relationshipToward(target);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping updateRelationship(object source, mixed target,
    mapping changes, mapping context, mapping metadata, mixed producer)
{
    mapping ret = ([]);
    if (!objectp(source) ||
        !function_exists("updateRelationshipToward", source))
    {
        raise_error("ERROR - relationship: Source has no relationship module.\n");
    }
    else
    {
        ret = source->updateRelationshipToward(target, changes,
            context, metadata, producer);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping modify(object source, mixed target,
    string dimension, int amount, mapping context)
{
    return updateRelationship(source, target, ([ dimension:amount ]),
        context, ([]), "relationship.modify");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int relationshipDimensionToward(object source, mixed target,
    string dimension)
{
    int ret = 0;
    if (!isValidDimension(dimension))
    {
        raise_error("ERROR - relationship: Invalid dimension.\n");
    }
    else
    {
        mapping record = relationshipToward(source, target);
        if (sizeof(record) && member(record["dimensions"], dimension))
        {
            ret = record["dimensions"][dimension];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasRelationshipToward(object source, mixed target)
{
    return sizeof(relationshipToward(source, target)) > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string classify(mapping values)
{
    string ret = "acquaintance";
    if (values["trust"] <= -60 || values["respect"] <= -60)
    {
        ret = "enemy";
    }
    else if (values["rivalry"] >= 60)
    {
        ret = "rival";
    }
    else if (values["trust"] >= 60 && values["respect"] >= 50 &&
        values["affection"] >= 40)
    {
        ret = "friend";
    }
    else if (values["trust"] >= 75 && values["respect"] >= 60)
    {
        ret = "trusted ally";
    }
    else if (values["trust"] >= 40 && values["respect"] >= 30)
    {
        ret = "ally";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string relationshipType(object source, mixed target)
{
    return source->relationshipSummary(target)["classification"];
}

/////////////////////////////////////////////////////////////////////////////
public nomask int validCondition(mixed condition)
{
    int ret = mappingp(condition) && stringp(condition["target"]) &&
        (condition["target"] == "owner" || condition["target"] == "target" ||
            identity(condition["target"]) != "") &&
        member(({ "toward", "from" }), condition["direction"]) >= 0;
    if (ret)
    {
        ret = (!member(condition, "classification") &&
            stringp(condition["dimension"]) &&
            isValidDimension(condition["dimension"]) &&
            (member(condition, "minimum") || member(condition, "maximum")) &&
            (!member(condition, "minimum") ||
                intp(condition["minimum"])) &&
            (!member(condition, "maximum") ||
                intp(condition["maximum"])) &&
            (!member(condition, "minimum") ||
                !member(condition, "maximum") ||
                condition["minimum"] <= condition["maximum"])) ||
            (stringp(condition["classification"]) &&
                member(({ "stranger", "acquaintance", "ally", "trusted ally",
                    "friend", "rival", "enemy" }),
                    condition["classification"]) >= 0 &&
                !member(condition, "dimension"));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int meetsCondition(object actor, mapping condition,
    object owner, object target)
{
    int ret = 0;
    if (validCondition(condition) && objectp(actor) &&
        function_exists("relationshipToward", actor))
    {
        mixed other = condition["target"];
        if (other == "owner")
        {
            other = owner;
        }
        else if (other == "target")
        {
            other = target;
        }
        if (identity(other) != "")
        {
            mapping record = condition["direction"] == "from" ?
                actor->relationshipFrom(other) :
                actor->relationshipToward(other);
            if (member(condition, "classification"))
            {
                ret = condition["classification"] ==
                    actor->relationshipSummary(other,
                        condition["direction"])["classification"];
            }
            else
            {
                int value = sizeof(record) ?
                    record["dimensions"][condition["dimension"]] : 0;
                ret = (!member(condition, "minimum") ||
                    value >= condition["minimum"]) &&
                    (!member(condition, "maximum") ||
                        value <= condition["maximum"]);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int matchesQuery(mapping record, mapping query)
{
    int ret = mappingp(query);
    if (ret)
    {
        foreach(string key in m_indices(query))
        {
            if (key == "target")
            {
                ret &&= record["target"] == identity(query[key]);
            }
            else
            {
                ret &&= isValidDimension(key) && intp(query[key]) &&
                    record["dimensions"][key] >= query[key];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *queryRelationships(object source, mapping query)
{
    mapping *ret = ({ });
    if (objectp(source) && function_exists("queryRelationships", source))
    {
        ret = source->queryRelationships(query);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int relationshipStrength(object source, mixed target)
{
    return source->relationshipSummary(target)["strength"];
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *relationshipHistoryFor(object source, mixed target,
    mapping query)
{
    return source->relationshipHistoryToward(target, query);
}
