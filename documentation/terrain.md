#### Dissecting a Terrain
In this section, I'll describe how to create a terrain by using /lib/environment/terrain/forest.c
as an example.

Let's look at the file and go through it line by line:

```
inherit "/lib/environment/terrain/baseTerrain.c";
```
This sets up your terrain object to inherit/use all of the goodies that make it a terrain
```
public void Setup()
{
    Name("forest");
```
We've given your terrain object a name. The one caveat to this is that you must use
a unique name (meaning that if you create a new terrain and give it the name "forest", you
will receive a polite, but firm, error message at compile time and will not be able to
use it.)
```
    addDescriptionTemplate("a ##Adjective##");
```
The `addDescriptionTemplate(string template, (optional) string state)` method is where
all the magic happens. Confused about the second, optional state parameter? All of the methods I'll be
discussing have that. We'll get back to it later. You can ignore it unless you're tying the
environment you're putting this into to a state machine for quests or other "fancy" behavior.

When someone enters an environment or looks around, a description is generated in the following way:

1. The name of your terrain is appended to the description template.
2. The current season's description is appended randomly from the list of available options (if any exist).
3. The current time of day's description is appended randomly from the list of available options (if any exist).
4. Specific weather details are then applied (rain, snow, fog, heat, etc)
5. A description as to how you arrived in the room is prepended.
6. If you have added adjectives and have specified `##Adjective##` in your template, this is replaced with a randomly-selected adjective that you specify.
7. In addition to ##Adjective##, you can also specify some efuns that can be executed as your description is evaluated. For example, `##call_other::file::/players/maeglin/orb.c::displayOrbs:#:` would call the function displayOrbs() without any parameters (denoted by the single # after displayOrbs) from the blueprint /players/maeglin/orb.c. This efun macro would be replaced inline when the environment is examined as shown in the gif below as the four color-coded items displayed in the room description: ![Orbs](http://RealmsMUD.org/images/intro.gif)

With the description template in place, we can now add some flavoring for the description that gets generated.

```
    addAdjectives(({ "sprawling forest",
        "forest thick with mighty trees; knotted arms rising upward",
        "grove of many trees",
        "towering forest",
        "lush forest",
        "serene forest"
    }));
```
The `addAdjectives(string *adjectives, (optional) string state)` method will add a series of adjectives, metaphors,
similies, or additional descriptive text that can be randomly added to the description template
for the terrain.
```
    addTimeOfDayDescription("dawn", ({ 
        ", the sinuous mists of the early morning caressing their limbs",
        " just waking with the first light of dawn",
        " wrapped in the new morn's light",
        " shedding the shadows of its night-time slumber"
    }));
```
The `addTimeOfDay(string timeFrame, string *descriptions, (optional) string state)` method will add a series
descriptions for a given time of day to the environment's description. Adding these descriptions
is strongly encouraged as they add a great deal of flavor to the description, but it is
optional - you do not need to add any. You can also add time of day descriptions ONLY
where you want to add special text instead of for all timeframes. 

The possible timeframes are specified in /lib/dictionaries/environmentDictionary.c in the `validTimesOfDay` variable.
```
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
```
The `addSeasonDescription(string season, string *descriptions, (optional) string state)` method will add a series
descriptions for a given season to the environment's description. As with time of day
descriptions, they are optional, but strongly encouraged. 

The possible seasons are specified in /lib/dictionaries/environmentDictionary.c in the `validSeasons` variable.

##### How does it look?
Putting all of this together, a terrain might look like this:
```
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest");
    addAdjectives(({ "sprawling forest",
        "forest thick with mighty trees; knotted arms rising upward",
        "grove of many trees",
        "towering forest",
        "lush forest",
        "serene forest"
    }));
    addTimeOfDayDescription("dawn", ({ 
        ", the sinuous mists of the early morning caressing their limbs",
        " just waking with the first light of dawn",
        " wrapped in the new morn's light",
        " shedding the shadows of its night-time slumber"
    }));
    addTimeOfDayDescription("morning", ({
        " lit from rays of light piercing through the canopy",
        " awash with the tender glow of the morning "
    }));
    addTimeOfDayDescription("noon", ({ 
        " bathed in the mid-day light",
        " lit by golden seams of light coming through the canopy"
    }));
    addTimeOfDayDescription("afternoon", ({
        " lit by the fullness of the day" }));
    addTimeOfDayDescription("evening", ({ 
        " still lit by the waning day's light" }));
    addTimeOfDayDescription("dusk", ({ 
        ", the details of which the last failing light of the day barely show" }));
    addTimeOfDayDescription("night", ({ 
        " outlined in the dark" }));
    addTimeOfDayDescription("midnight", ({ 
        " scarcely outlined in eery black" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
    addSeasonDescription("spring", ({ " with leaves just beginning to bud" }));
    addSeasonDescription("summer", ({ " with branches laden with leaves" }));
    addSeasonDescription("autumn", ({ " carpeting the ground in fallen leaves of red, yellow, and orange" }));

    addDescriptionTemplate("a ##Adjective##");
}
```
Interiors are specified in exactly the same manner.

##### Interactable Items
TBD

##### Lighting
For terrains, lighting is tied directly to the time-of-day and weather while for interiors, the default behavior
is to have no light by default. What that means is that either an environmental object that is a light source
will need to be added OR you will need to set up your interior as a source of light OR those entering the room will need to supply their own light source if they
wish to see anything.

Any terrain/interior/other item can become a source of light through the use of the
`addSourceOfLight(int magnitude, (optional) string state, (optional) string timeOfDay, (optional) string season)` method.
The magnitude of the light source can be either positive or negative (for example, a curtain over a window or an
item that releases a magical 'darkness' aura might be negative). If the sum of all acting sources
of light are positive, the environment will be light and otherwise, it will be dark.

The optional parameters limit the light source to specific states, times of day, and seasons respectively.

#### Active Lighting

TBD

#### Decaying Light Sources

TBD

##### Light Level Descriptions
TBD

##### State Machines
TBD

##### Harvestable Resources
TBD
