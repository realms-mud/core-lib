//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private int observationCount;
private mapping lastCriteria;

public int has(string module)
{
    return module == "research";
}

public string colorConfiguration()
{
    return "none";
}

public void setObservationCount(int count)
{
    observationCount = count;
}

public int countObservations(mapping criteria)
{
    lastCriteria = criteria + ([]);
    return observationCount;
}

public mapping queriedCriteria()
{
    return lastCriteria;
}