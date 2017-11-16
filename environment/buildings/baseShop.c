//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

mapping list = ([]);
string *ProhibitedTypes = ({});
string Name = "Shop";
string WelcomeMessage = "Welcome";

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string name(string newName)
{
    if (newName && stringp(newName))
    {
        Name = newName;
    }
    return Name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string welcomeMessage(string newMessage)
{
    if (newMessage && stringp(newMessage))
    {
        WelcomeMessage = newMessage;
    }
    return WelcomeMessage;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int storeItem(object item, int isPermanent)
{
    int ret = 0;

    if (item && (member(inherit_list(item), "lib/items/item.c") > -1) &&
        !item->query("no sell"))
    {
        ret = 1;
        object dictionary = load_object("/lib/dictionaries/materialsDictionary.c");

        list[object_name(item)] = ([
            "name": item->query("name"),
            "value": item->query("value"),
            "type": item->query("type"),
            "quality": dictionary->getMaterialQualityFormatter(item),
            "data": item->query("all")
        ]);

        if (isPermanent)
        {
            list[object_name(item)]["permanent"] = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping hereIsStuff()
{
    return list + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateShopInteraction(object user)
{
    object selectorObj = clone_object("/lib/items/inventory/shopSelector.c");
    move_object(selectorObj, user);
    selectorObj->setStore(this_object());
    selectorObj->setProhibitedTypes(ProhibitedTypes);
    selectorObj->registerEvent(this_object());
    selectorObj->initiateSelector(user);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canPurchaseItem(object item)
{
    return 1;
}