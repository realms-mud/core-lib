//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping ResearchChoices;

/////////////////////////////////////////////////////////////////////////////
public mapping choices()
{
    return ResearchChoices;
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchChoiceAvailable(object caller, mapping data)
{
    ResearchChoices = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchChoiceChosen()
{
    raise_error("event handler: onResearchChoiceChosen called");
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchPathChosen()
{
    raise_error("event handler: onResearchPathChosen called");
}
