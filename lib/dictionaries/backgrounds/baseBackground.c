//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private int SetupCompleted = 0;
private string StartLocation = StartLocation();

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    if (!SetupCompleted)
    {
        Setup();
        SetupCompleted = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setStartingLocation(string location)
{
    if (stringp(location) && (file_size(location) > 0))
    {
        StartLocation = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntro(object player)
{
}

/////////////////////////////////////////////////////////////////////////////
public void introductionCompleted(object player)
{
    move_object(player, StartLocation);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateBackgroundStory(object player)
{
    displayIntro(player);
}
