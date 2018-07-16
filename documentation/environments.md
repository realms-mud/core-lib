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

The pre-fabricated terrains are located in: /lib/environment/terrain. You can either
specify a fully-qualified file path or the name of the terrain:

`setTerrain("/lib/environment/terrain/forest.c")` is equivalent to
`setTerrain("forest")`

##### For interior locations:
call `void setInterior(string interior)`
The pre-fabricated interiors are located in: /lib/environment/interiors

`setInterior("/lib/environment/interiors/library.c")` is equivalent to
`setInterior("library")`

It is implortant to note that you can only set either the terrain or the interior.
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

That's a fair question. Building your own terrain or interior is pretty easy. Let's
dissect /lib/environment/terrain/forest.c:
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
2. The current time of day's description is appended randomly from the list of available options (if any exist).
3. Specific weather details are then applied (rain, snow, fog, heat, etc)
4. A description as to how you arrived in the room is prepended.
5. If you have added adjectives and have specified `##Adjective##` in your template, this is replaced with a randomly-selected adjective that you specify.
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