//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef experiencesModule_h
#define experiencesModule_h

private nosave int observationPlayerId;

/////////////////////////////////////////////////////////////////////////////
protected int experienceOwnerId()
{
    return observationPlayerId;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void loadExperiences(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        observationPlayerId = data["is guest"] ? 0 : data["playerId"];
    }
}

#endif
