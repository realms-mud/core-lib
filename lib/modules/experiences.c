//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/experiences.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int recordsObservations()
{
    return experienceOwnerId() > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping recordObservation(mapping observation,
    int contextCaptured)
{
    mapping ret = 0;
    int playerId = experienceOwnerId();
    object actor = mappingp(observation) && member(observation, "actor") ?
        observation["actor"] : this_object();

    if (playerId && mappingp(observation) &&
        objectp(actor) && (actor == this_object() ||
            actor == previous_object()))
    {
        object service = getService("experiences");
        observation += ([ "actor":actor ]);
        if (!contextCaptured && (!member(observation, "context") ||
            mappingp(observation["context"])))
        {
            observation["context"] = service->buildObservationContext(
                actor, observation);
        }
        ret = service->normalizeObservation(observation);
        if (ret)
        {
            service->storeObservation(playerId, ret);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping *queryObservations(mapping criteria,
    int limit, int offset)
{
    mapping *ret = ({ });
    int playerId = experienceOwnerId();
    if (playerId && mappingp(criteria))
    {
        ret = getService("experiences")->queryPlayerObservations(
            playerId, criteria, limit, offset);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int countObservations(mapping criteria)
{
    int ret = 0;
    int playerId = experienceOwnerId();
    if (playerId && mappingp(criteria))
    {
        ret = getService("experiences")->countPlayerObservations(
            playerId, criteria);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int hasObservation(mapping criteria, int minimum)
{
    int ret = 0;
    int playerId = experienceOwnerId();
    if (playerId && mappingp(criteria))
    {
        ret = getService("experiences")->hasPlayerObservation(
            playerId, criteria, minimum > 0 ? minimum : 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int countExperiencedType(string type)
{
    return stringp(type) ? countObservations(([ "type":type ])) : 0;
}
