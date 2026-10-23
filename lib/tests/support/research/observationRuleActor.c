//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private int observationCount;
private mapping lastCriteria;
private mapping researchCounts = ([]);

/////////////////////////////////////////////////////////////////////////////
public void setResearchObservationCount(string research, int count)
{
    researchCounts[research] = count;
}

/////////////////////////////////////////////////////////////////////////////
public int has(string module)
{
    return module == "research";
}

/////////////////////////////////////////////////////////////////////////////
public string colorConfiguration()
{
    return "none";
}

/////////////////////////////////////////////////////////////////////////////
public void setObservationCount(int count)
{
    observationCount = count;
}

/////////////////////////////////////////////////////////////////////////////
public int countObservations(mapping criteria)
{
    lastCriteria = criteria + ([]);
    return member(researchCounts, criteria["research"]) ?
        researchCounts[criteria["research"]] : observationCount;
}

/////////////////////////////////////////////////////////////////////////////
public int hasObservation(mapping criteria, int minimum)
{
    return countObservations(criteria) >= minimum;
}

/////////////////////////////////////////////////////////////////////////////
public mapping queriedCriteria()
{
    return lastCriteria;
}
