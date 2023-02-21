//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/bonuses.c";
virtual inherit "/lib/environment/modules/environment/description.c";
virtual inherit "/lib/environment/modules/environment/elements.c";
virtual inherit "/lib/environment/modules/environment/exits.c";
virtual inherit "/lib/environment/modules/environment/generated-region.c";
virtual inherit "/lib/environment/modules/environment/harvest.c";
virtual inherit "/lib/environment/modules/environment/legacy.c";
virtual inherit "/lib/environment/modules/environment/lighting.c";
virtual inherit "/lib/environment/modules/environment/region.c";
virtual inherit "/lib/environment/modules/environment/shop.c";
virtual inherit "/lib/environment/modules/environment/state.c";

private nosave int SetupCompleted = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask string environmentName()
{
    return regreplace(object_name(this_object()), "([^#]*)(#[0-9]+|)",
        "\\1");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void cloneEnvironment()
{
    environmentalElements["cloned"] = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string cloneOwner()
{
    return member(environmentalElements, "clone owner") ?
        environmentalElements["clone owner"] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public int id(string item)
{
    return isEnvironmentalElement(item);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int moveToDestination(object player, string direction,
    string destination, object region, string state)
{
    int canMove = 1;
    if (destination)
    {
        object door = 0;
        object originalLocation = environment(this_player());

        if (member(environmentalElements["doors"], state) &&
            member(environmentalElements["doors"][state], destination))
        {
            door = environmentalElements["doors"][state][destination];

            if (door->isLocked())
            {
                canMove = 0;
                door->displayLockedMessage(this_player());
            }
            else
            {
                door->displayMoveMessage(this_player(), direction);
            }
        }

        if (canMove)
        {
            this_player()->move(destination, direction, objectp(door), region);

            object party = this_player()->getParty();
            if (party)
            {
                party->moveFollowers(this_player(), destination, direction, region);
            }

            if (door)
            {
                door->displayOpenMessage(this_player());
                door->displayCloseMessage(this_player(), originalLocation);
            }
        }
    }

    return destination && stringp(destination);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int move(string str)
{
    string direction = query_verb();
    string destination = 0;
    object region = 0;

    string state = currentState();
    if (member(exits, state) && member(exits[state], direction) &&
        stringp(exits[state][direction]))
    {
        destination = exits[state][direction];
    }
    else if (member(exits, state) && member(exits[state], direction) &&
        mappingp(exits[state][direction]))
    {
        destination = exits[state][direction]["destination"];
        region = exits[state][direction]["region"];
    }
    else if (member(exits, "default") && member(exits["default"], direction) &&
        stringp(exits["default"][direction]))
    {
        destination = exits["default"][direction];
        state = "default";
    }
    else if (member(exits, "default") && member(exits["default"], direction) &&
        mappingp(exits["default"][direction]))
    {
        state = "default";
        destination = exits[state][direction]["destination"];
        region = exits[state][direction]["region"];
    }

    return moveToDestination(this_player(), direction, destination, 
        region, state);
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpEncounter(object player)
{

}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    if (objectp(this_player()) && present(this_player()))
    {
        if (objectp(stateMachine()))
        {
            currentState(stateMachine()->getCurrentState());
        }
        if (this_player())
        {
            remove_action(1);
        }
        string *directions = ({});
        if (member(exits, currentState()) && sizeof(exits[currentState()]))
        {
            directions += m_indices(exits[currentState()]);
        }
        if (member(exits, "default") && sizeof(exits["default"]))
        {
            directions += m_indices(exits["default"]);
        }

        if (sizeof(directions))
        {
            directions = m_indices(mkmapping(directions));
            foreach(string direction in directions)
            {
                add_action("move", direction);
            }
        }

        setUpActiveLighting();
        setUpEncounter(this_player());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void reset()
{
    object shopObj = getShop();
    if (objectp(shopObj))
    {
        shopObj->updateShopInventory();
    }
    createStateObjects();
}

/////////////////////////////////////////////////////////////////////////////
public nomask void create()
{
    if (!SetupCompleted)
    {
        Setup();
        SetupCompleted = 1;
    }
    reset();
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getCloneOwner(object actor, object party)
{
    string owner = party ? party->partyName() : actor->RealName();
    if (!owner)
    {
        owner = "default";
    }
    return owner;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void enterEnvironment(object actor, object party)
{
    object location = this_object();

    string owner = getCloneOwner(actor, party);
    if (environmentalElements["cloned"])
    {
        if (member(instances, owner) && objectp(instances[owner]))
        {
            location = instances[owner];
        }
        else if(!clonep(this_object()))
        {
            environmentalElements["clone owner"] = owner;
            location = clone_object(object_name(this_object()));
            instances[owner] = location;

            if (getRegion())
            {
                location->setCoordinates(getRegion(), 
                                         xCoordinate(), 
                                         yCoordinate());
            }
        }
    }

    if (stateMachinePath())
    {
        location->setupStateMachine(owner);
    }

    move_object(actor, location);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void addDecorator(string decorator, string state)
{
    if (!state)
    {
        state = "default";
    }

    if (!member(environmentalElements, "decorator"))
    {
        environmentalElements["decorator"] = ([]);
    }
    environmentalElements["decorator"][state] = decorator;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string decoratorType(string state)
{
    string ret = 0;

    if (member(environmentalElements, "decorator"))
    {
        if (!state)
        {
            state = "default";
        }

        if (member(environmentalElements["decorator"], state))
        {
            ret = environmentalElements["decorator"][state];
        }
        else if (member(environmentalElements["decorator"], "default"))
        {
            ret = environmentalElements["decorator"]["default"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    return baseIcon;
}
