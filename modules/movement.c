//*****************************************************************************
// Class: movement
// File Name: movement.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
    
/////////////////////////////////////////////////////////////////////////////
public nomask void runAway()
{
    object originalLocation = environment();
    if(originalLocation && function_exists("exits", originalLocation))
    {
        string *possibleDestinations = originalLocation->exits();
        object combat = getService("combat");
        object materialAttributes = getService("materialAttributes");
        
        if(possibleDestinations && ((combat && combat->triggerWimpy()) || 
          (materialAttributes && !materialAttributes->queryProperty("no fear"))))
        {
            int attemptsToRun = 0;
            while((attemptsToRun < 12) && (originalLocation == environment()))
            {
                string direction = 
                    possibleDestinations[random(sizeof(possibleDestinations))];
                command(direction);
                attemptsToRun++;
            }
            
            if(originalLocation == environment())
            {
                write("You tried, but failed to run away.\n");
                say(sprintf("%s tried, but failed to run away.", 
                    materialAttributes->Name()));
            }
            else
            {
                write("Your legs run away with you!\n");
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int move()
{

}

