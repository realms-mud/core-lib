//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/state.c";

private mapping bonuses = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int environmentalBonusTo(string bonus, object actor)
{
    int ret = 0;
    string actorName = objectp(actor) ? actor->RealName() : 0;
    if (actorName)
    {
        string key = sprintf("%s#%s", actorName, currentState());

        if (!member(bonuses, key))
        {
            bonuses[key] = ([]);
        }

        if (!member(bonuses[key], bonus))
        {
            bonuses[key][bonus] = 0;

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
                        if (elementObj)
                        {
                            bonuses[key][bonus] += 
                                elementObj->environmentalBonusTo(
                                    currentState(), 
                                    this_object(),
                                    bonus,
                                    actor);
                        }
                    }
                }
            }
        }
        ret = bonuses[key][bonus];
    }
    return ret;
}
