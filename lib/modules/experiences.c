//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/experiences.h"

/////////////////////////////////////////////////////////////////////////////
private nomask object experiencesService()
{
    return getService("experiences");
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping recordObservation(mapping observation)
{
    mapping ret = 0;
    object service = experiencesService();

    if (service && mappingp(observation))
    {
        if (!member(observation, "actor") ||
            (observation["actor"] == this_object()))
        {
            observation += ([
                "actor":this_object()
            ]);

            if (!member(observation, "context") ||
                mappingp(observation["context"]))
            {
                observation["context"] = service->buildObservationContext(
                    this_object(), observation);
            }
            ret = service->normalizeObservation(observation);
            if (ret)
            {
                mapping existing = 0;
                if (observationsPersisted)
                {
                    foreach(mapping pending in pendingObservations)
                    {
                        if (pending["ID"] == ret["ID"])
                        {
                            existing = pending;
                            break;
                        }
                    }
                }
                if (existing)
                {
                    ret = existing;
                }
                else
                {
                    mapping entry = cloneObservationEntry(ret);
                    observations += ({ entry });
                    pendingObservations += ({ entry });
                    indexObservation(entry);
                }
                ret = cloneObservationEntry(ret);
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *experiencesLog()
{
    return map(observations, #'cloneObservationEntry);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping *queryObservations(mapping query,
    int limit, int offset)
{
    object service = experiencesService();
    mapping *ret = ({ });

    if (service && mappingp(query))
    {
        mapping *candidates = observationsPersisted ? pendingObservations :
            observationCandidates(query);
        foreach(mapping observation in candidates)
        {
            if (service->matchesObservation(observation, query))
            {
                ret += ({ cloneObservationEntry(observation) });
            }
        }
        if (observationsPersisted)
        {
            object database = clone_object("/lib/modules/secure/dataAccess.c");
            int savedCount = database->countObservationsByPlayer(
                observationsPlayerName, query, pendingObservationIds());
            mapping *pending = ret;
            ret = ({ });
            int start = offset > 0 ? offset : 0;
            if (start < savedCount)
            {
                ret = database->queryObservationsByPlayer(
                    observationsPlayerName, query, limit, start,
                    pendingObservationIds());
            }
            int pendingStart = start > savedCount ? start - savedCount : 0;
            int remaining = limit > 0 ? limit - sizeof(ret) : sizeof(pending);
            if (remaining > 0 && pendingStart < sizeof(pending))
            {
                int end = pendingStart + remaining - 1;
                if (end >= sizeof(pending))
                {
                    end = sizeof(pending) - 1;
                }
                ret += pending[pendingStart..end];
            }
            destruct(database);
        }
        else if (offset > 0 || limit > 0)
        {
            int start = offset > 0 ? offset : 0;
            int end = limit > 0 ? start + limit - 1 : sizeof(ret) - 1;
            ret = start < sizeof(ret) ? ret[start..end] : ({ });
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int countObservations(mapping query)
{
    int ret = 0;
    object service = experiencesService();
    if (service && mappingp(query))
    {
        mapping *candidates = observationsPersisted ? pendingObservations :
            observationCandidates(query);
        foreach(mapping observation in candidates)
        {
            if (service->matchesObservation(observation, query))
            {
                ret++;
            }
        }
        if (observationsPersisted)
        {
            object database = clone_object("/lib/modules/secure/dataAccess.c");
            ret += database->countObservationsByPlayer(
                observationsPlayerName, query, pendingObservationIds());
            destruct(database);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasObservation(mapping query)
{
    int ret = 0;
    object service = experiencesService();
    if (service && mappingp(query))
    {
        mapping *candidates = observationsPersisted ? pendingObservations :
            observationCandidates(query);
        foreach(mapping observation in candidates)
        {
            if (service->matchesObservation(observation, query))
            {
                ret = 1;
                break;
            }
        }
        if (!ret && observationsPersisted)
        {
            object database = clone_object("/lib/modules/secure/dataAccess.c");
            ret = database->hasObservationByPlayer(observationsPlayerName,
                query, pendingObservationIds());
            destruct(database);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int countExperiencedType(string type)
{
    return stringp(type) ? countObservations(([ "type":type ])) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping experiencesSummary()
{
    return experiencesService()->summarizeObservations(observations);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string mostFrequentExperiencedContext(string contextKey)
{
    string ret = "";
    int count = 0;
    mapping summary = experiencesSummary();

    if (stringp(contextKey) && member(summary["context"], contextKey))
    {
        foreach(string value in m_indices(summary["context"][contextKey]))
        {
            if (summary["context"][contextKey][value] > count)
            {
                count = summary["context"][contextKey][value];
                ret = value;
            }
        }
    }
    return ret;
}