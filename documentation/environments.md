# Environments De-Mystified
![A quest](http://RealmsMUD.org/images/environments.gif)

At first glance, creating environments (what old timers on Realms knew as rooms)
in the new core library can seem a bit daunting. I know that as soon as I start
talking about state machines and adding objects instead of straight-out descriptions,
I get a really hateful glare from Sonja. But, I wasn't being a jerk when I started
down this path. I wanted to make something awesome. One goal was to both make area
creation far more flexible without having to "roll your own" solution while making
it intuitive and very easy to use, thereby drastically decreasing the barrier to
entry for creating the Realms world. I don't know if I succeeded in that latter
bit, but it's definitely more flexible than the old library's room.c was.

Throwing objects in isn't easier, Maeglin. That's a fair criticism. However, I had
another motivation for this: text can't be translated into graphical objects easily.
This approach can be. I do have plans to eventually create a 3D client for the mud
and I've also entertained the notion of doing sprite/tile-based stuff as well.

So with the motivation behind us, let's take a look at how this is actually
accomplished.

### Dissecting an Environment

The shell of any environment you create needs to inherit /lib/environment/environment.c
and you set up your environment by overloading the `public void Setup()` method.

For example:
```
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}
```
This is, admittedly, a very uninteresting environment, so let's take a closer look.

Creating an environment is broken down into one required step and several additional
optional steps:
- Set the environment's terrain type OR set what type of interior it is.
- Add environmental items - these are:
  -  Buildings (terrain only) - these are large "man-made" structures someone entering the environment might see.
  -  Terrain Features - These are things like caves, river beds, stands of trees, and so on.
  -  Miscellaneous items (both terrain and interiors) - These are objects used to describe an environment such as a signpost, a chest, a table, tapestries, chairs, a dock/pier, and so on.
- Add cloned objects - these would be monsters/NPCs, weapons, armor, treasures, and so on
- Add shop/shop inventory - If the environment is a shop, you can specify the type of shop and set up the buying/selling of items.
- Add exits - You can attach environments togetherby setting up actions and the desired destination.
- If the environment is part of a larger region / group of environments, you can set its coordinates within that region
- Set an additional long description
- Set a short description.
- Set up a state machine to drive interesting behaviors. 

Let's take a closer look at each of these steps.

#### Setting an Environment

There are a significant number of pre-fabricated terrains and interiors that a wizard
can use to create a room. However, flexibility is key and environments support wizards
creating their own custom terrains and interiors.

##### For terrains / outdoors locations:
call `void setTerrain(string terrain)`

The pre-fabricated terrains are located in: /lib/environment/terrain and any custom
terrain must inherit from `/lib/environment/terrain/baseTerrain.c`. You can either
specify a fully-qualified file path or the name of the terrain:

`setTerrain("/lib/environment/terrain/forest.c")` is equivalent to
`setTerrain("forest")`

##### For interior locations:
call `void setInterior(string interior)`
The pre-fabricated interiors are located in: /lib/environment/interiors and any custom
interior must inherit from `/lib/environment/interiors/baseInterior.c`.

`setInterior("/lib/environment/interiors/library.c")` is equivalent to
`setInterior("library")`

It is important to note that you can only set either the terrain or the interior.
If you try to set both, an exception will be thrown.

Here's a complete example of a forest environment:
 ```
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
}
```
This will have a fully-featured forest that supports time of day and season.

Now, I know what you're thinking: "So I use setTerrain and... magic happens? I don't
like that. How does this really work? How can I create my own terrain/interior?"

That's a fair question. Building your own terrain or interior is pretty easy. [If
you are interested, I have dissected the creation of /lib/environment/terrain/forest.c
here](terrain.md)

#### Features
Once you have the terrain or interior set up for an environment, you can add features.
The original intent was to break down each environment into a 3x3 grid and allow
the wizard to place objects either "front-and-center" in the room (ie: location not specified),
or a cardinal / primary intercardinal direction (ie: n, s, e, w, ne, nw, se, sw). Having
said that, items can be placed in an arbitrary location and multiple items can be
placed in the same general area. There is a work item to change this to a coordinate system,
but that is currently not implemented and may never be.

The syntax for creating features - be they buildings, features, or static items - is identical
to that for creating terrain or interiors with the only difference being the class that you are
inheriting from as will be discussed in each of the following sections. [Again, see how to create /lib/environment/terrain/forest.c
here](terrain.md)

There are three methods to add these features, the first one being for buildings:

###### Buildings
`varargs void addBuilding(string building, string location, string path, string state)`

This method is the most interesting of the group. The only required parameter is `building`
as this is either the name or fully-qualified path for the building file.
```
addBuilding("wainwright");
addBuilding("/lib/environment/shops/wainwright.c");
```

These two calls are functionally-equivalent. It is important to note that for custom-generated
buildings, that if you wish to use the name, the building must be registered with the
environment dictionary at mud start-up time. You can alternatively use the fully-qualified path
and that option is always available to you.

The second parameter specifies where within the environment that the building you're adding is:
```
addBuilding("/lib/environment/shops/wainwright.c", "north");
addBuilding("/lib/environment/shops/swordsmith.c", "just right of the Wainwright");
```

The third parameter is used only if the building has a door / entryway in this room. The parameter
specifies the path of another environment this one exits into for that building.
```
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/shop.c");
```

The fourth parameter specifies the state that an attached state machine must be in for an exit
to be active.
```
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/shop.c");
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/spiffyNewShop.c", "neat stuff");
```

The pre-fabricated buildings can be found in: `/lib/environment/buildings`. All custom buildings
must inherit from `/lib/environment/buildings/baseBuilding.c`.

If the building you wish to add has a door that should open/close and potentially lock, there is a special
method for adding a building of this nature.

`varargs void addBuildingWithDoor(string building, mixed location, string path, string door, string key, string state);`

This is identical to the `addBuilding` method with the notable addition of two new parameters: door and key. The door
parameter is a string that is the file path to the door environmental element that will be used to describe the door. This must inherit 
`/lib/environment/doors/baseDoor.c`. The (optional) key parameter is the file path to the key object that can lock/unlock the door. This key must inherit 
`/lib/items/key.c`.

###### Other Features and Static Items
In addition to buildings, you can also add other features or static items.

```
varargs void addFeature(string building, string location);
varargs void addItem(string item, string location);
```
A feature (found in `/lib/environment/features`) is any "large scale" thing that might be found in an environment such as a bluff, 
a stand of trees, a cliff, a river, and so on. Features must inherit from `/lib/environment/features/baseFeature.c`. 
An item is a small-scale static item (`/lib/environment/items`) and must inherit from `/lib/environment/items/baseItem.c`.

As with buildings, the first parameter is either the name or fully-qualified path for the feature
or item file. The rules for the location are the same as those for buildings.

One special class of item is one that inherits from `/lib/environment/items/baseContainer.c`. These
items provide the means to store non-static items (items a player can pick up such as a weapon
or money, for example). 

###### Lighting
By default, environments do not have lighting set. If a terrain is added, the lighting for time of day, weather, and season
will be taken into account. If an interior is added, there will be no lighting unless it was specifically set up for
the interior in question. However, other environmental items (buildings, features, miscellaneous items) that are light
sources can be added. [See the 'Lighting' section of the environmental object discussion for further details.](terrain.md)

There is an override for this behavior available. If you need to always have your environment light, you can overload
```
protected int alwaysLight()
{
    return 0;
}
```

If it returns any non-zero value, then the details of the environment will always be visible independent of any other criteria.

###### Inhibiting Movement
By default, living creatures - be they players or monsters - can freely move around in environments. If you wish to change this
behavior, there are two hooks provided:
```
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
```
Simply implement your own version of these functions to either prevent movement out of or into the environment in question.
  
###### Shops
If the room is a shop (meaning that you can do transactions in this location), there is a method
for adding support for the game's shop mechanics:
```
void addShop(string shop);
```
The pre-fabricated shop inventories can be found in: `/lib/environment/shopInventories`. All custom shop
inventories must inherit from `/lib/environment/shopInventories/baseShop.c`.
![A shop](http://RealmsMUD.org/images/shop.gif)

The above is what you would get by adding this method call to your Setup() function:
```
addShop("/lib/environment/shopInventories/swordsmith.c");
```

#### Adding Monsters, Equipment, and Other Cloned Items
```
varargs void addObject(string file, string state);
```
This method is only intended for use with fully-defined, clonable programs - if you wish to assemble a monster
on the fly, for example, you will need to do that logic using your own custom handler. [See the discussion on monsters for details.](monsters.md)

#### Adding Exits
In addition to the `addBuilding` method, there are a couple other means of adding an exit to an environment.
```
varargs void addExit(string direction, string path, string state);
```
The `addExit` method takes several parameters - the `direction` verb (north, south, up, down, etc), the fully-qualified `path` of the destination environment, and optionally, the `state` during which this exit is usable. 

```
varargs void addExitWithDoor(string direction, string path, string door, string key, string state);
```
The `addExitWithDoor` method is similar to the `addExit` method. The additional `door` and `key` parameters are the door object being used (see /lib/environment/doors for examples) and the optional key object if the door is locked / lockable (see /lib/environment/doors/baseDoor.c). The key object must inherit /lib/items/key.c 

#### Regions
```
void setCoordinates(string region, int x, int y);
```
TBD

##### Region Auto-Generation

TBD

##### Map Decorators

TBD

#### Additional Descriptions
```
varargs void setAdditionalLongDescription(string description, string state);
```
This additional long description can have embedded efun calls in it as described as point number 7
in the [`addDescriptionTemplate`](terrain.md) section of the environmental element discussion. 
TBD

#### Short Descriptions
```
void setShortDescription(string newShort);
```
TBD

#### Using State Machines
```
void setStateMachine(string newSM);
```
TBD

##### Environmental Bonuses
TBD
