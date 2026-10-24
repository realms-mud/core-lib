//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/experiences.c";

private mapping *observationCalls = ({ });

/////////////////////////////////////////////////////////////////////////////
protected int experienceOwnerId()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected object experiencesService()
{
    return this_object();
}

/////////////////////////////////////////////////////////////////////////////
public mapping normalizeObservation(mapping observation)
{
    return getService("experiences")->normalizeObservation(observation);
}

/////////////////////////////////////////////////////////////////////////////
public mapping buildObservationContext(object actor, mapping observation)
{
    return getService("experiences")->buildObservationContext(
        actor, observation);
}

/////////////////////////////////////////////////////////////////////////////
public void storeObservation(int playerId, mapping observation)
{
    observationCalls += ({ deep_copy(observation) });
}

/////////////////////////////////////////////////////////////////////////////
public mapping *queryPlayerObservations(int playerId, mapping criteria,
    int limit, int offset)
{
    mapping *ret = ({ });
    limit = limit > 0 ? min(limit, 100) : 50;
    offset = max(offset, 0);
    foreach(mapping observation in observationCalls)
    {
        if (getService("experiences")->matchesObservation(
            observation, criteria))
        {
            if (offset)
            {
                offset--;
            }
            else if (sizeof(ret) < limit)
            {
                ret += ({ deep_copy(observation) });
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int countPlayerObservations(int playerId, mapping criteria)
{
    int ret = 0;
    foreach(mapping observation in observationCalls)
    {
        ret += getService("experiences")->matchesObservation(
            observation, criteria);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int hasPlayerObservation(int playerId, mapping criteria, int minimum)
{
    int count = 0;
    int ret = minimum <= 0;
    object service = getService("experiences");
    foreach(mapping observation in observationCalls)
    {
        if (ret)
        {
            break;
        }
        count += service->matchesObservation(observation, criteria);
        ret = count >= minimum;
    }
    return ret;
}
