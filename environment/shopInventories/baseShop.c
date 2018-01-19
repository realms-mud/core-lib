//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping list = ([]);
private string *ProhibitedTypes = ({});
private string Name = "Shop";
private string WelcomeMessage = "Welcome";
private string ShopType = "unknown";
private string ShopItemSubType = "all";
private int ItemsToGenerate = 15;

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "shop";
}

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
public nomask varargs string shopType(string newType)
{
    if (newType && stringp(newType))
    {
        ShopType = newType;
    }
    return ShopType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string shopSubType(string newType)
{
    if (newType && stringp(newType))
    {
        ShopItemSubType = newType;
    }
    return ShopItemSubType;
}

/////////////////////////////////////////////////////////////////////////////
public int randomItemsToGenerate()
{
    return ItemsToGenerate;
}

/////////////////////////////////////////////////////////////////////////////
public void setRandomItemsToGenerate(int numberOfItems)
{
    ItemsToGenerate = numberOfItems;
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
            "description": item->long(),
            "value": item->query("value"),
            "type": item->query("type"),
            "subType": dictionary->getBlueprintModifier(item, "subtype"),
            "quality": dictionary->getMaterialQualityFormatter(item),
            "summary": dictionary->getItemSummary(item),
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
public nomask varargs int buyItem(string key)
{
    int ret = 0;

    if (member(list, key))
    {
        ret = 1;
        if (!member(list[key], "permanent"))
        {
            m_delete(list, key);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping storeInventory()
{
    return list + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetInventory()
{
    list = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateShopInteraction(object user)
{
    object selectorObj = clone_object("/lib/environment/shopInventories/shopSelector.c");
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
public nomask void onSelectorAborted(object caller)
{
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canPurchaseItem(object item)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}
