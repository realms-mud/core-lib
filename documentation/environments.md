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
~~~c
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
}
~~~
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
~~~c
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
}
~~~
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
~~~c
addBuilding("wainwright");
addBuilding("/lib/environment/shops/wainwright.c");
~~~

These two calls are functionally-equivalent. It is important to note that for custom-generated
buildings, that if you wish to use the name, the building must be registered with the
environment service at mud start-up time. You can alternatively use the fully-qualified path
and that option is always available to you.

The second parameter specifies where within the environment that the building you're adding is:
~~~c
addBuilding("/lib/environment/shops/wainwright.c", "north");
addBuilding("/lib/environment/shops/swordsmith.c", "just right of the Wainwright");
~~~

The third parameter is used only if the building has a door / entryway in this room. The parameter
specifies the path of another environment this one exits into for that building.
~~~c
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/shop.c");
~~~

The fourth parameter specifies the state that an attached state machine must be in for an exit
to be active.
~~~c
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/shop.c");
addBuilding("/lib/environment/shops/wainwright.c", "north", "/players/maeglin/spiffyNewShop.c", "neat stuff");
~~~

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

~~~c
varargs void addFeature(string building, string location);
varargs void addItem(string item, string location);
~~~
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
~~~c
protected int alwaysLight()
{
    return 0;
}
~~~

If it returns any non-zero value, then the details of the environment will always be visible independent of any other criteria.

###### Inhibiting Movement
By default, living creatures - be they players or monsters - can freely move around in environments. If you wish to change this
behavior, there are two hooks provided:
~~~c
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
~~~
Simply implement your own version of these functions to either prevent movement out of or into the environment in question.
  
###### Shops
If the room is a shop (meaning that you can do transactions in this location), there is a method
for adding support for the game's shop mechanics:
~~~c
void addShop(string shop);
~~~
The pre-fabricated shop inventories can be found in: `/lib/environment/shopInventories`. All custom shop
inventories must inherit from `/lib/environment/shopInventories/baseShop.c`.
![A shop](http://RealmsMUD.org/images/shop.gif)

The above is what you would get by adding this method call to your Setup() function:
~~~c
addShop("/lib/environment/shopInventories/swordsmith.c");
~~~

#### Adding Monsters, Equipment, and Other Cloned Items
~~~c
varargs void addObject(string file, string state);
~~~
This method is only intended for use with fully-defined, clonable programs - if 
you wish to assemble a monster on the fly, for example, you will need to do 
that logic using your own custom handler. [See the discussion on monsters for details.](monsters.md)

#### Adding Exits
In addition to the `addBuilding` method, there are a couple other means of adding an exit to an environment.
~~~c
varargs void addExit(string direction, string path, string state);
~~~
The `addExit` method takes several parameters - the `direction` verb (north, south, up, 
down, etc), the fully-qualified `path` of the destination environment, and optionally, 
the `state` during which this exit is usable. 

~~~c
varargs void addExitWithDoor(string direction, string path, string door, string key, string state);
~~~
The `addExitWithDoor` method is similar to the `addExit` method. The additional 
`door` and `key` parameters are the door object being used (see /lib/environment/doors 
for examples) and the optional key object if the door is locked / lockable (see 
/lib/environment/doors/baseDoor.c). The key object must inherit /lib/items/key.c 

#### Regions
~~~c
void setCoordinates(string region, int x, int y);
~~~

Regions are groups of related environments that can be automatically generated 
or manually crafted. When you set coordinates for an environment, you're placing 
it within a larger regional context. The region parameter is the name of the
region, and x, y are the coordinates within that region.

For example:
~~~c
setCoordinates("temple-interior", 0, 0);
~~~

This places the environment at coordinates (0,0) within the "temple-interior" 
region. The coordinate system typically uses (0,0) as a reference point, with 
positive x extending east and positive y extending north.

##### Region Auto-Generation

The system supports automatic generation of regions using several sophisticated 
algorithms. This is handled through the generate-region.c module, which can create:

- **Terrain-based regions**: Automatically generates outdoor areas with appropriate terrain transitions
- **Settlement generation**: Creates villages, towns, and cities with logical building placement
- **Path generation**: Automatically creates roads, trails, and connections between locations
- **Room generation**: Creates interior spaces with appropriate connections and features

To use auto-generation, you typically create a region controller file that defines the parameters:

~~~c
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setName("mystical forest");
    setDimensions(10, 10);
    setTerrainType("forest");
    setSettlementDensity(0.1);
    setPathDensity(0.3);
    generateRegion();
}
~~~

##### Map Decorators

Map decorators are sophisticated visual representation objects that control 
how environments appear on maps and in potential graphical clients. They 
provide detailed ASCII, Unicode, and color-coded representations of 
environmental layouts, room types, and connections.

###### Adding Map Decorators

Map decorators are added using the `addDecorator` method:

~~~c
varargs void addDecorator(string decorator, string state);
~~~

The decorator parameter specifies the visual representation to use, 
while the optional state parameter makes the decorator conditional on 
the environment's state machine.

Examples:
~~~c
addDecorator("ruined interior amethyst floor");
addDecorator("ruined interior amethyst floor north south", "first test");
addDecorator("keep interior east-west hallway", "normal");
addDecorator("keep interior courtyard with pillar", "ceremony");
~~~

###### Decorator Definition Files

Map decorators are defined in header files located in `/lib/services/regions/icons/`:

- **keep-interior-icons.h** - Keep and castle interior representations
- **ruined-interior-icons.h** - Ruined building and dungeon interiors
- **forest-icons.h** - Forest and woodland terrain representations
- **mountain-icons.h** - Mountain and rocky terrain representations
- **desert-icons.h** - Desert and arid terrain representations
- **water-icons.h** - Water and aquatic terrain representations
- **urban-icons.h** - City and town representations
- **underground-icons.h** - Cave and underground representations

###### Decorator Structure

Each decorator is defined as a complex mapping that supports multiple display modes:

~~~c
"decorator_name": ([
    "colors": ([
        "none": "",                    // No color support
        "grayscale": "\x1b[0;38;5;237m",  // Grayscale terminals
        "3-bit": "\x1b[0;36m",           // 8-color terminals
        "8-bit": "\x1b[0;38;5;237m",     // 256-color terminals
        "24-bit": "\x1b[0;38;2;86;92;86m", // True color terminals
        "icons": ([
            "floor": ([
                "none": "",
                "grayscale": "\x1b[0;38;5;234m",
                "3-bit": "\x1b[0;31m",
                "8-bit": "\x1b[0;38;5;234m",
                "24-bit": "\x1b[0;38;2;28;36;28m",
            ]),
            "door": ([
                "none": "",
                "grayscale": "\x1b[0;38;5;251m",
                "3-bit": "\x1b[0;33m",
                "8-bit": "\x1b[0;38;5;100m",
                "24-bit": "\x1b[0;38;2;102;102;38m",
            ])
        ])
    ]),
    "ascii": ({ 
        ({ "=", "=", "=" }),
        ({ "#floor# ", "#floor# ", "#floor# " }),
        ({ "=", "=", "=" }) 
    }),
    "unicode": ({ 
        ({ "\u2550", "\u2550", "\u2550" }),
        ({ "#floor#\u2591", "#floor#\u2591", "#floor#\u2591" }),
        ({ "\u2550", "\u2550", "\u2550" }) 
    })
])
~~~

###### Multi-Character Set Support

Decorators support different character sets for maximum compatibility:

**ASCII Mode** - Uses basic ASCII characters for universal compatibility:
~~~c
"ascii": ({ 
    ({ "|", " ", "|" }),
    ({ "|", " ", "|" }),
    ({ "|", " ", "|" }) 
})
~~~

**Unicode Mode** - Uses extended Unicode characters for enhanced visual appeal:
~~~c
"unicode": ({ 
    ({ "\u2551", "\u2591", "\u2551" }),
    ({ "\u2551", "\u2591", "\u2551" }),
    ({ "\u2551", "\u2591", "\u2551" }) 
})
~~~

###### Color System Integration

The decorator system integrates with the MUD's comprehensive color system:

**Color Depth Support**:
- **none**: No color codes (text-only clients)
- **grayscale**: Monochrome terminals with shading
- **3-bit**: Traditional 8-color terminals
- **8-bit**: 256-color terminals
- **24-bit**: True color terminals with full RGB support

**Dynamic Color Substitution**:
The system supports template-based color substitution where `#element#` 
placeholders are replaced with appropriate colors:
~~~c
"#floor#\u2591"  // Becomes colored floor character
"#door#\u2581"   // Becomes colored door character
"#grass#\u2591"  // Becomes colored grass character
~~~

###### Decorator Categories

**Hallway Decorators**:
- `keep interior east-west hallway` - Horizontal corridor
- `keep interior north-south hallway` - Vertical corridor
- `keep interior 4-way hallway` - Four-way intersection
- `keep interior east-west hallway north entry` - Hallway with north door
- `keep interior north-south hallway east-west entry` - Cross-shaped intersection

**Room Decorators**:
- `keep interior floor` - Basic interior floor
- `keep interior courtyard` - Open courtyard area
- `keep interior courtyard with pillar` - Courtyard with central pillar
- `keep interior courtyard with path` - Courtyard with walkway

**Corner Decorators**:
- `keep interior northwest corner` - Room corner
- `keep interior northeast corner` - Room corner
- `keep interior southwest corner` - Room corner
- `keep interior southeast corner` - Room corner

**Wall Decorators**:
- `keep interior north wall` - Northern wall
- `keep interior south wall` - Southern wall
- `keep interior east wall` - Eastern wall
- `keep interior west wall` - Western wall

**Specialized Decorators**:
- `keep interior south gatehouse` - Fortified entrance
- `keep interior large staired entrance left` - Grand stairway
- `keep interior large staired entrance right` - Grand stairway

###### Entry and Exit Variations

Many decorators have variations that show entrances and exits:

~~~c
// Basic hallway
addDecorator("keep interior east-west hallway");

// Hallway with north entrance
addDecorator("keep interior east-west hallway north entry");

// Hallway with multiple entrances
addDecorator("keep interior east-west hallway north-south entry");
~~~

This system allows for precise control over how connections between rooms are visually represented.

###### State-Dependent Decorators

Decorators can change based on the environment's state machine:

~~~c
// Default state
addDecorator("keep interior courtyard", "default");

// During ceremony
addDecorator("keep interior courtyard with pillar", "ceremony");

// Under siege
addDecorator("keep interior courtyard battle damaged", "siege");
~~~

###### Creating Custom Decorators

To create custom decorators, add entries to the appropriate icon header file:

~~~c
"my custom room": ([
    "colors": ([
        "none": "",
        "3-bit": "\x1b[0;32m",
        "24-bit": "\x1b[0;38;2;0;128;0m",
        "icons": ([
            "special": ([
                "3-bit": "\x1b[0;33m",
                "24-bit": "\x1b[0;38;2;255;255;0m",
            ])
        ])
    ]),
    "ascii": ({ 
        ({ "+", "-", "+" }),
        ({ "|", "#special#*", "|" }),
        ({ "+", "-", "+" }) 
    }),
    "unicode": ({ 
        ({ "\u250c", "\u2500", "\u2510" }),
        ({ "\u2502", "#special#\u2605", "\u2502" }),
        ({ "\u2514", "\u2500", "\u2518" }) 
    })
])
~~~

###### Integration with Mapping Systems

Map decorators integrate with several mapping systems:

**Regional Maps**: Show the layout of entire regions with appropriate terrain symbols
**Local Maps**: Display detailed room-by-room layouts with precise connections
**Overhead Maps**: Provide bird's-eye view of areas with architectural details
**Tactical Maps**: Show combat-relevant terrain features and obstacles

###### Advanced Decorator Features

**Multi-Level Representation**:
Some decorators represent multi-level structures:
~~~c
"keep interior large staired entrance left": ([
    // Shows stairs leading to different levels
    "ascii": ({ 
        ({ "#grass# ", "#grass# ", "#grass# " }),
        ({ "#floor#-", "#floor2#-", "#floor#-" }),
        ({ "#stairs#=", "#stairs#=", "#stairs#=" }) 
    })
])
~~~

**Conditional Elements**:
Decorators can include conditional elements that appear based on state:
~~~c
"keep interior gatehouse": ([
    // Different representations for open/closed gates
    // Portcullis shown based on security state
])
~~~

**Lighting Integration**:
Decorators can reflect lighting conditions:
~~~c
// Darker colors for unlit areas
// Brighter colors for well-lit areas
// Special symbols for magical lighting
~~~

This comprehensive decorator system provides rich visual feedback for 
players exploring the world, whether through text-based maps or future 
graphical clients, while maintaining compatibility across different 
terminal types and color capabilities.


#### Additional Descriptions
~~~c
varargs void setAdditionalLongDescription(string description, string state);
~~~

This method allows you to add supplementary descriptive text that appears after 
the standard environmental description. The description can contain embedded efun 
calls and template variables as described in the environmental element documentation.

The optional state parameter allows you to make the additional description 
conditional on the current state of the environment's state machine. This enables 
dynamic descriptions that change based on events, time, or other conditions.

Examples:
~~~c
setAdditionalLongDescription("A gentle breeze stirs the leaves overhead.");
setAdditionalLongDescription("The area is filled with the acrid smell of smoke.", "on fire");
setAdditionalLongDescription("##Season## flowers bloom along the path.", "spring");
~~~

#### Short Descriptions
~~~c
void setShortDescription(string newShort);
~~~

The short description appears in the status line and brief room descriptions. It 
should be concise and capture the essence of the location. If not set, the system 
will generate an appropriate short description based on the terrain or interior 
type and any major features.

Examples:
~~~c
setShortDescription("a moonlit forest clearing");
setShortDescription("the grand entrance hall");
setShortDescription("a narrow mountain pass");
~~~

#### Using State Machines
~~~c
void setStateMachine(string newSM);
~~~

State machines provide sophisticated event-driven behavior for environments. 
They allow environments to change over time, respond to player actions, and 
create dynamic, evolving areas.

The state machine file must inherit from `/lib/environment/stateMachine.c` and 
define states, transitions, and behaviors. Common uses include:

- **Time-based changes**: Environments that change with day/night cycles
- **Event responses**: Environments that react to player actions or game events
- **Quest integration**: Environments that change based on quest progress
- **Seasonal variations**: Environments that evolve with the seasons
- **Combat states**: Environments that change during or after combat

Example state machine setup:
~~~c
setStateMachine("/lib/environment/stateMachines/forgeFire.c");
~~~

This might control a forge that can be lit and extinguished, changing the 
environment's lighting, available actions, and descriptions.

##### Environmental Bonuses
Environmental bonuses provide mechanical benefits to characters in specific 
locations. These are managed through the bonuses.c module and can affect:

- **Skill bonuses**: Improvements to specific skills while in the environment
- **Attribute bonuses**: Temporary increases to character attributes
- **Healing bonuses**: Enhanced recovery rates for health, spell points, or stamina
- **Resistance bonuses**: Protection against specific damage types or effects

Environmental bonuses can be:
- **Permanent**: Always active while in the environment
- **Conditional**: Active only under certain conditions or states
- **Time-based**: Active during specific times of day or seasons
- **Faction-based**: Available only to specific character types or factions

Examples of environmental bonus setup:
~~~c
// In a library environment
addBonus("research", 5);
addBonus("magic theory", 3);

// In a temple environment
addBonus("healing", 8);
addBonus("resist evil", 20);

// In a forge environment
addBonus("blacksmithing", 10);
addBonus("weapon smithing", 5);
~~~

These bonuses are automatically applied when characters enter the environment 
and removed when they leave, providing immersive mechanical benefits that 
encourage exploration and strategic positioning.

#### Complete Environment Examples

Here are some complete examples showing how these various components work together:

##### Forest Clearing with Seasonal Changes
~~~c
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    
    addFeature("/lib/environment/features/clearing.c", "center");
    addFeature("/lib/environment/features/stream.c", "east");
    addItem("/lib/environment/items/campfire.c", "center");
    
    addExit("north", "/domains/forest/rooms/path1.c");
    addExit("south", "/domains/forest/rooms/path2.c");
    
    setAdditionalLongDescription("Wildflowers carpet the ground in a "
        "riot of color.", "spring");
    setAdditionalLongDescription("The clearing is filled with the "
        "golden light of autumn.", "fall");
    
    setShortDescription("a peaceful forest clearing");
    
    // Bonus for nature-related activities
    addBonus("survival", 8);
    addBonus("herbalism", 5);
}
~~~

##### Temple Interior with State Machine
~~~c
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/temple.c");
    setCoordinates("temple-interior", 0, 0);
    
    addFeature("/lib/environment/features/altar.c", "north");
    addItem("/lib/environment/items/lighting/brazier.c", "northeast");
    addItem("/lib/environment/items/lighting/brazier.c", "northwest");
    addItem("/lib/environment/items/pews.c", "center");
    
    addExit("south", "/domains/temple/rooms/entrance.c");
    addExit("east", "/domains/temple/rooms/side-chapel.c");
    
    setStateMachine("/lib/environment/stateMachines/templeRitual.c");
    
    setAdditionalLongDescription("The altar glows with divine light, "
        "and the air thrums with sacred energy.", "blessed");
    
    setShortDescription("the temple sanctuary");
    
    // Healing bonuses in consecrated space
    addBonus("healing", 10);
    addBonus("resist evil", 25);
    addBonus("divine magic", 8);
}
~~~

##### Shop Environment
~~~c
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/shop.c");
    
    addItem("/lib/environment/items/counter.c", "center");
    addItem("/lib/environment/items/shelves.c", "east");
    addItem("/lib/environment/items/shelves.c", "west");
    addItem("/lib/environment/items/lighting/lantern.c", "ceiling");
    
    addShop("/lib/environment/shopInventories/weaponsmith.c");
    
    addExit("out", "/domains/town/rooms/market-square.c");
    
    setShortDescription("a cluttered weapon shop");
    
    // Bonus for appraising weapons
    addBonus("appraisal", 5);
    addBonus("weapon lore", 3);
}
~~~

This comprehensive system provides enormous flexibility for creating rich, 
dynamic environments that enhance gameplay through both narrative and mechanical elements.
