//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

private int currentFireState;
private string *fireDescriptions = ({});

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addFireDescriptions(string *descriptions)
{
    if (pointerp(descriptions) && sizeof(descriptions) &&
        stringp(descriptions[0]))
    {
        fireDescriptions = descriptions + ({});
    }
    else
    {
        raise_error("ERROR in baseFire.c: The fire descriptions "
            "must be an array of strings.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void decayFire(string state, object environment)
{
    remove_call_out("decayFire");

    if (lightSourceIsActive(state, environment))
    {
        if (currentFireState <= 1)
        {
            deactivateLightSource(state, environment);
            currentFireState = 0;
        }
        else
        {
            currentFireState--;

            descriptionData["active light sources"][environment]["template"] =
                fireDescriptions[currentFireState];
            descriptionData["active light sources"][environment]["magnitude"] =
                currentFireState;

            call_out("decayFire", 150, state, environment);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int processLightSourceActivation(string state, object environment)
{
    currentFireState = 0;
    if (canActivateLightSource(state) && sizeof(fireDescriptions) > 1)
    {
        currentFireState = sizeof(fireDescriptions) - 1;

        descriptionData["active light sources"][environment]["template"] =
            fireDescriptions[currentFireState];

        call_out("decayFire", 150, state, environment);
    }
    return currentFireState;
}


/////////////////////////////////////////////////////////////////////////////
protected string getDescriptionFromSet()
{
    object environment = ((member(inherit_list(previous_object()), 
        "lib/environments/environment.c") > -1) || !this_player()) ? 
        previous_object() :
        environment(this_player());

    return capitalize(
        (member(descriptionData, "active light sources") &&
            member(descriptionData["active light sources"], environment)) ?
        descriptionData["active light sources"][environment]["template"] :
        getSourceOfLightTemplate(State, currentFireState, environment));
}
