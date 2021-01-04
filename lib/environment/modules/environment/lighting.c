//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/state.c";

/////////////////////////////////////////////////////////////////////////////
private nomask int getElementLighting()
{
    int ret = 0;

    foreach(string elementType in({ "terrain", "interior", "feature", 
        "building", "item", "door" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = m_indices(environmentalElements[elementType]);
            foreach(string element in elements)
            {
                object elementObj =
                    getDictionary("environment")->environmentalObject(element);
                if (elementObj && 
                    (!this_player() || elementObj->elementIsAvailable(this_player())))
                {
                    ret += elementObj->isSourceOfLight(currentState(),
                        this_object());
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int alwaysLight()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int minimumNeededLightLevel()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isIlluminated()
{
    int ret = alwaysLight();
    if (!ret)
    {
        ret = sizeof(environmentalElements["terrain"]) ?
            getDictionary("environment")->ambientLight() : 0;

        int otherLight = getElementLighting();
        if (otherLight > ret)
        {
            ret = otherLight;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpActiveLighting()
{
    int haveActiveLights = 0;
    foreach(string elementType in({ "terrain", "feature", "building", "item" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = filter(
                m_indices(environmentalElements[elementType]),
                (: $3->environmentalObject($1) &&
                    $3->environmentalObject($1)->canActivateLightSource($2) :),
                currentState(), getDictionary("environment"));

            haveActiveLights ||= sizeof(elements);
        }
    }

    if(haveActiveLights)
    {
        add_action("activateLights", "light");
        add_action("activateLights", "ignite");
        add_action("deactivateLights", "extinguish");
        add_action("deactivateLights", "put out");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *getActiveLightElements(string filter)
{
    string *ret = ({});
    foreach(string elementType in({ "terrain", "feature", "building", "item" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = filter(
                m_indices(environmentalElements[elementType]),
                (: ($4->environmentalObject($1) &&
                    $4->environmentalObject($1)->canActivateLightSource($2) &&
                    (!$3 || (member($4->environmentalObject($1)->aliases($2), 
                        $3) > -1))) :),
                currentState(), filter, getDictionary("environment"));
            if (sizeof(elements))
            {
                ret += elements;
            }
        }
    }
    return sort_array(ret, (: $1 > $2 :));
}

/////////////////////////////////////////////////////////////////////////////
private nomask int displayLightMessage(string *elements, object initiator,
    string messageTemplate)
{
    int ret = 0;

    if (sizeof(elements))
    {
        ret = 1;
        string itemList;
        if (sizeof(elements) > 1)
        {
            itemList = implode(
                elements[0..(sizeof(elements) - 2)], ", ") +
                ((sizeof(elements) == 2) ? " and " : ", and ") +
                elements[sizeof(elements) - 1];
        }
        else
        {
            itemList = elements[0];
        }

        object parser = load_object("/lib/core/messageParser.c");
        parser->displayMessage(messageTemplate + itemList, initiator, 0,
            "action", "environment", 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int manipulateLights(string whichLights, string action,
    string verb)
{
    string *activatedItems = ({});
    string *elements = getActiveLightElements(whichLights);

    if (sizeof(elements))
    {
        foreach(string element in elements)
        {
            object elementObj =
                getDictionary("environment")->environmentalObject(element);

            if (elementObj &&
                (!this_player() || elementObj->elementIsAvailable(this_player())))
            {
                activatedItems += ({ elementObj->displayName() });
                call_direct(elementObj, sprintf("%sLightSource", action),
                    currentState(), this_object());
            }
        }
    }

    return displayLightMessage(activatedItems, this_player(),
        sprintf("##InitiatorName## ##Infinitive::%s## the following: ", verb));
}

/////////////////////////////////////////////////////////////////////////////
public nomask int activateLights(string whichLights)
{
    return manipulateLights(whichLights, "activate", "light");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int deactivateLights(string whichLights)
{
    return manipulateLights(whichLights, "deactivate", "extinguish");
}
