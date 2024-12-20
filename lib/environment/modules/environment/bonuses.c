//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/state.c";

private mapping bonuses = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int environmentalBonusTo(string bonus, object actor,
    object target)
{
    int ret = 0;
    string actorName = objectp(actor) ? actor->RealName() : 0;
    if (actorName)
    {
        string key = sprintf("%s#%s#%O", actorName, currentState(), target);

        if (!member(bonuses, key))
        {
            bonuses[key] = ([]);
        }

        if (!member(bonuses[key], bonus))
        {
            bonuses[key][bonus] = ({ });

            foreach(string elementType in({ "terrain", "interior", "feature",
                "building", "item", "door" }))
            {
                if (sizeof(environmentalElements[elementType]))
                {
                    string *elements = 
                        m_indices(environmentalElements[elementType]);
                    foreach(string element in elements)
                    {
                        object elementObj =
                            getDictionary("environment")->environmentalObject(element);
                        if (elementObj &&
                            (member(elementObj->bonuses(), bonus) > -1))
                        {
                            bonuses[key][bonus] += ({ elementObj });
                        }
                    }
                }
            }
        }

        if (sizeof(bonuses[key][bonus]))
        {
            foreach(object element in bonuses[key][bonus])
            {
                if (objectp(element) && element->elementIsAvailable(actor))
                {
                    ret += element->environmentalBonusTo(
                        currentState(), this_object(), bonus, actor, target);
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string bonusStatistics(object user, string item)
{
    string ret = 0;

    foreach(string elementType in({ "terrain", "interior", "feature",
        "building", "item", "door" }))
    {
        if (sizeof(environmentalElements[elementType]))
        {
            string *elements = 
                m_indices(environmentalElements[elementType]);
            foreach(string element in elements)
            {
                object elementObj =
                    getDictionary("environment")->environmentalObject(element);
                if (elementObj && elementObj->elementIsAvailable(user))
                {
                    ret += elementObj->getBonusDescriptions(
                        this_object(), user) + "\n";
                }
            }
        }
    }

    if (!ret)
    {
        ret = "There are no bonuses being applied from this environment.\n";
    }
    return ret;
}
