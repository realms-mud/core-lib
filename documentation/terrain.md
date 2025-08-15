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

The possible timeframes are specified in /lib/services/environmentService.c in the `validTimesOfDay` variable.
```
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
```
The `addSeasonDescription(string season, string *descriptions, (optional) string state)` method will add a series
descriptions for a given season to the environment's description. As with time of day
descriptions, they are optional, but strongly encouraged. 

The possible seasons are specified in /lib/services/environmentService.c in the `validSeasons` variable.

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
Terrain objects can include interactable items that players can examine or interact with. These are 
added using the `addItemTemplate(string template, (optional) string state)` method. The item 
template defines what players see when they use the "look" command on the terrain object itself.

Items can also have aliases added using the `addAlias(string alias, (optional) string state)` 
method, allowing players to reference the terrain by alternative names. For example, a 
forest might have aliases like "trees", "woods", or "woodland".

Example:
```
   addItemTemplate("a dense forest with towering trees and thick undergrowth"); 
   addAlias("trees"); 
   addAlias("woods"); 
   addAlias("woodland");
```


##### Lighting
For terrains, lighting is tied directly to the time-of-day and weather while for 
interiors, the default behavior is to have no light by default. What that means 
is that either an environmental object that is a light source will need to be added 
OR you will need to set up your interior as a source of light OR those entering 
the room will need to supply their own light source if they wish to see anything.

Any terrain/interior/other item can become a source of light through the use of the
`addSourceOfLight(int magnitude, (optional) string state, (optional) string timeOfDay, (optional) string season)` method.
The magnitude of the light source can be either positive or negative (for example, a curtain over a window or an
item that releases a magical 'darkness' aura might be negative). If the sum of all acting sources
of light are positive, the environment will be light and otherwise, it will be dark.

The optional parameters limit the light source to specific states, times of day, and seasons respectively.

#### Active Lighting

Active lighting sources are light sources that can be turned on and off, such as 
torches, lanterns, or magical lights. These are created using the 
`addActiveSourceOfLight(int magnitude, string template, int activeByDefault, (optional) string state)` method.

Parameters:
- `magnitude`: The light level provided when active (1-10 scale)
- `template`: The description template used when the light source is active
- `activeByDefault`: Whether the light source starts active (1) or inactive (0)
- `state`: Optional state limitation

Example:
`addActiveSourceOfLight(8, "a brightly burning torch mounted on the wall", 1);`

Active light sources can be controlled through the 
`activateLightSource(string state, object environment)` and 
`deactivateLightSource(string state, object environment)` methods.

#### Decaying Light Sources

Some light sources decay over time, such as campfires or torches. To create 
decaying light sources, you override the 
`processLightSourceActivation(string state, object environment)` method in your 
terrain class. This method is called when the light source is activated and 
should return the current light magnitude.

Example implementation:
```
protected int processLightSourceActivation(string state, object environment) 
{ 
    // Custom logic to reduce light over time 
    int currentMagnitude = ::processLightSourceActivation(state, environment); 
    
    // Implement decay logic here return currentMagnitude; 
}
```


##### Light Level Descriptions
Different description templates can be used based on the current light level. 
The system supports five light levels:

- `addNearDarkDescriptionTemplate(string template, (optional) string state)`: For light levels 1-2
- `addLowLightDescriptionTemplate(string template, (optional) string state)`: For light levels 3-4  
- `addDimLightDescriptionTemplate(string template, (optional) string state)`: For light levels 5-6
- `addSomeLightDescriptionTemplate(string template, (optional) string state)`: For light levels 7-8
- `addDescriptionTemplate(string template, (optional) string state)`: For light levels 9-10 (full light)

Example:
```
addNearDarkDescriptionTemplate("a barely visible forest shrouded in deep darkness"); 
addLowLightDescriptionTemplate("a dimly lit forest with shadowy forms"); 
addDimLightDescriptionTemplate("a forest with limited visibility"); 
addSomeLightDescriptionTemplate("a reasonably well-lit forest"); 
addDescriptionTemplate("a brightly lit ##Adjective##");
```


##### State Machines
The optional `state` parameter in most methods allows you to tie terrain behavior to 
state machines. States represent different conditions or phases of the terrain. You can:

- Set the current state with `currentState(string newState)`
- Get available states with `states()`
- Add state-specific descriptions, bonuses, and other features

This is useful for quest-driven environments, seasonal changes, or dynamic terrain 
that responds to player actions.

Example:
```
addDescriptionTemplate("a peaceful ##Adjective##", "normal"); 
addDescriptionTemplate("a war-torn ##Adjective##", "battle"); 
addBonus("stealth", 2, "normal"); addPenalty("stealth", 2, "battle");
```


##### Harvestable Resources
Terrain can provide harvestable resources that players can gather. 
Resources are added using the 
`harvestableResource(string name, int quantity, string resourceFile, string harvestedDescription, (optional) string *aliases)` method.

Parameters:
- `name`: The name of the resource
- `quantity`: How many can be harvested before depletion
- `resourceFile`: Path to the item file that will be cloned when harvested
- `harvestedDescription`: Description shown when some resources have been harvested
- `aliases`: Alternative names for the resource

Example:
```
harvestableResource("berries", 
    5, 
    "/lib/domains/town/obj/berries", 
    "with several berry bushes that have been picked clean", 
    ({ "blackberries", "fruit" }));
```


##### Harvest Limitations
You can restrict when and how resources can be harvested:

- `limitHarvestBySeason(string name, string season)`: Only available in specific seasons
- `limitHarvestByTimeOfDay(string name, string timeOfDay)`: Only available at certain times
- `limitHarvestByMoonPhase(string name, string moonPhase)`: Limited by moon phase
- `limitHarvestByState(string name, string state)`: Limited by terrain state
- `limitHarvestBySkill(string name, string skill, int value)`: Requires minimum skill level
- `harvestRequiresTool(string name, string tool)`: Requires specific equipment
- `harvestRequiresOneOfTool(string name, string *tools)`: Requires one of several tools

Example:
```
harvestableResource("rare herbs", 
    3, 
    "/lib/domains/town/obj/herbs", 
    "with disturbed soil where herbs once grew"); 
    limitHarvestBySeason("rare herbs", "spring"); 
    limitHarvestByTimeOfDay("rare herbs", "dawn"); 
    limitHarvestBySkill("rare herbs", "herbalism", 50); 
    harvestRequiresTool("rare herbs", "herb knife");
```

##### Environmental Bonuses
Terrain can provide bonuses or penalties to player actions and attributes. These 
are added using `addBonus(string bonusName, int value, (optional) string state)` 
and `addPenalty(string bonusName, int value, (optional) string state)`.

The bonus name must be valid according to the bonuses service. Common bonuses include:
- Combat bonuses: "melee", "dodge", "parry"
- Stealth bonuses: "stealth", "hiding"
- Magic bonuses: "magic", "spellcraft"
- Skill bonuses: specific skill names

Example:
```
addBonus("stealth", 3);  // +3 stealth bonus 
addPenalty("magic", 2);  // -2 magic penalty 
addBonus("herbalism", 5); // +5 herbalism bonus
```


##### Bonus Limitations
Like harvesting, bonuses can be limited by various factors:

- `limitBonusBySeason(string name, string season)`
- `limitBonusByTimeOfDay(string name, string timeOfDay)`
- `limitBonusByMoonPhase(string name, string moonPhase)`
- `limitBonusByState(string name, string state)`
- `limitBonusBySkill(string name, string skill, int value)`
- `limitBonusByAttribute(string name, string attribute, int value)`
- `bonusRequiresEquipment(string name, string tool)`
- `bonusRequiresOneOfEquipment(string name, string *tools)`

Additional limitations include:
- `limitBonusByIntoxication(string name, int value)`
- `limitBonusByDrugEffect(string name, int value)`
- `limitBonusByNearnessToDeath(string name, int value)`
- `limitBonusBySpellPointsDrained(string name, int value)`
- `limitBonusByStaminaDrained(string name, int value)`

Example:
```
addBonus("stealth", 5); 
limitBonusByTimeOfDay("stealth", "night"); 
limitBonusBySkill("stealth", "stealth", 25);
```


##### Environmental Limitors
Environmental limitors control when terrain features are visible or accessible 
to players. These use the same limitation system as bonuses but apply to 
the terrain's visibility and interaction.

Common limitors include:
- `limitDisplayBySeason(string season)`
- `limitDisplayByTimeOfDay(string timeOfDay)`
- `limitDisplayByMoonPhase(string moonPhase)`
- `limitDisplayByState(string state)`
- `limitDisplayBySkill(string skill, int value)`
- `limitDisplayByAttribute(string attribute, int value)`
- `limitDisplayByEquipment(string tool)`
- `limitDisplayByQuest(string quest)`
- `limitDisplayByResearch(string research)`
- `limitDisplayByTrait(string trait)`

Example:
```
// Hidden grove only visible to those with high perception 
limitDisplayBySkill("perception", 75);

// Magical glade only visible during full moon 
limitDisplayByMoonPhase("full moon");

// Secret area only available after completing a quest 
limitDisplayByQuest("find_hidden_entrance");
```

##### Domain Enhancements
Domain enhancements allow terrain to integrate with the domain management 
system, providing bonuses and effects to buildings, troops, henchmen, and 
resources within a domain. These enhancements tie environmental elements to 
the complex domain mechanics including construction, military units, trade, 
and resource management.

#### Building Enhancements
Terrain can provide bonuses to buildings constructed within the domain 
through building effects. These affect construction time, capacity, and functionality:

Methods for building enhancements 
- `addBuildingBonus(string building, string bonus, mixed value, (optional) string state);`
- `addBuildingEffect(string building, string effect, mapping data, (optional) string state);`
- `addBuildingCapacityBonus(string building, int bonus, (optional) string state);`
- `addBuildingDurationBonus(string building, int bonus, (optional) string state);`
- `addBuildingCostBonus(string building, int bonus, (optional) string state);`
- `addBuildingResourceBonus(string building, string resource, int bonus, (optional) string state);`
- `addBuildingResourceEffect(string building, string resource, string effect, mapping data, (optional) string state);`
- `addBuildingResourceCapacityBonus(string building, string resource, int bonus, (optional) string state);`
- `addBuildingResourceDurationBonus(string building, string resource, int bonus, (optional) string state);`
- `addBuildingResourceCostBonus(string building, string resource, int bonus, (optional) string state);`

Example terrain with building enhancements:
```
// Forest terrain that enhances wooden construction 
addBuildingBonus("lumber mill", "production", (["quantity bonus": 25])); 
addBuildingBonus("carpenter", "wood construction", (["duration bonus": 15])); 
addBuildingDurationBonus("wooden church", -100); // Faster construction in forest 

addBuildingCapacityBonus("lumber yard", 500); // Increased storage capacity
```

#### Troop Enhancements
Terrain can provide bonuses and penalties to military units based on the environment. These affect combat effectiveness, morale, and movement:

Methods for troop enhancements 
- `addTroopBonus(string troopType, string bonus, int value, (optional) string state);` 
- `addTroopPenalty(string troopType, string penalty, int value, (optional) string state);` 
- `addTroopEffect(string troopType, string effect, mapping data, (optional) string state);`

Example terrain with troop effects:
```
// Mountain terrain favoring archers but hindering cavalry 
addTroopBonus("archer", "skill", 5); 
addTroopBonus("crossbowman", "skill", 3); 
addTroopPenalty("light cavalry", "movement", 2); 
addTroopPenalty("heavy cavalry", "movement", 3); 
addTroopEffect("mountain troops", "terrain bonus", (["type": "mountain", "value": 10]));
```

#### Henchman Enhancements
Terrain can affect henchman effectiveness and available henchman types:

Methods for henchman enhancements 
- `addHenchmanBonus(string henchmanType, string skill, int bonus, (optional) string state);`
- `addHenchmanCapacity(string henchmanType, int capacity, (optional) string state);`
- `addHenchmanAvailability(string henchmanType, int availability, (optional) string state);`

Example terrain with henchman effects:
```
// Forest terrain enhancing nature-based henchmen 
addHenchmanBonus("druid", "herbalism", 10); 
addHenchmanBonus("druid", "nature lore", 15); 
addHenchmanBonus("ranger", "tracking", 8); 
addHenchmanCapacity("druid", 3); // Can support up to 3 druids 
addHenchmanAvailability("druid", 150); // 150% normal recruitment chance
```

#### Resource Production
Terrain can generate domain-level resources that feed into the 
construction and trade systems:

Methods for resource production 
- `addResourceProduction(string resource, string scarcity, int quantity, (optional) string state);`
- `addResourceBonus(string resource, int bonus, (optional) string state);`
- `addResourceStorageBonus(string resource, int capacity, (optional) string state);`
- `addResourceCostBonus(string resource, int bonus, (optional) string state);`
- `addResourceDurationBonus(string resource, int bonus, (optional) string state);`
- `addResourceEffect(string resource, string effect, mapping data, (optional) string state);`
- `addResourceHarvestLimit(string resource, int limit, (optional) string state);`
- `addResourceHarvestTime(string resource, int time, (optional) string state);`


Example terrain with resource production:
```
// Forest terrain producing wood resources 
addResourceProduction("wood", "common", 10); // Produces 10 common wood per cycle 
addResourceProduction("rare wood", "uncommon", 2); // Produces 2 uncommon rare wood 
addResourceBonus("wood", 25); // 25% bonus to wood production 
addResourceStorageBonus("wood", 1000); // +1000 wood storage capacity
```


#### Trade Enhancements
Terrain can affect trade routes and commercial activities:

Methods for trade enhancements 
- `addTradeBonus(string tradeType, int bonus, (optional) string state);`
- `addTradeRoute(string destination, string goods, int modifier, (optional) string state);`
- `addTradeGood(string good, int value, int availability, (optional) string state);`
- `addTradeTax(string good, int taxRate, (optional) string state);`
- `addTradeCost(string good, int cost, (optional) string state);`
- `addTradeDuration(string good, int duration, (optional) string state);`
- `addTradeEffect(string good, string effect, mapping data, (optional) string state);`
- `addTradeLimit(string good, int limit, (optional) string state);`

Example terrain with trade effects:
```
// Coastal terrain enhancing maritime trade 
addTradeBonus("maritime", 20); // 20% bonus to sea trade 
addTradeRoute("distant port", "fish", 150); // Profitable fish trade route 
addTradeGood("pearls", 500, 25); // Valuable but rare pearls 
addTradeGood("salt", 50, 200); // Common salt production
```

#### Advanced Domain Integration
For complex domain mechanics, terrain can implement custom domain interfaces:

Custom domain enhancement methods 
- `public nomask int domainDefenseBonus(string location, string attackType);`
- `public nomask mapping domainResourceModifiers(string location);`
- `public nomask string *availableDomainUpgrades(string location);`
- `public nomask int domainConstructionTimeModifier(string location, string building);`

Example advanced integration:
```
// Terrain that provides complex domain bonuses 
public nomask int domainDefenseBonus(string location, string attackType) 
{ 
    int ret = 0;
    if (attackType == "siege") 
    {
        ret = -10; // Vulnerable to siege in open terrain 
    }
    else if (attackType == "cavalry")
    {
        ret = 5; // Some protection against cavalry 
    }
    return 0; 
}

public nomask mapping domainResourceModifiers(string location) 
{ 
    return ([ 
        "wood": 125, // 25% bonus to wood production 
        "stone": 75, // 25% penalty to stone production 
        "food": 110  // 10% bonus to food production 
    ]); 
}
```

#### Integration with Existing Systems
Domain enhancements work seamlessly with existing terrain features:

```
// Complete terrain with domain integration inherit "/lib/environment/terrain/baseTerrain.c";
public void Setup() 
{ 
    Name("fertile plains");
    // Basic terrain features
    addDescriptionTemplate("##Adjective## stretching to the horizon");
    addAdjectives(({ "vast fertile plains", "rolling grasslands" }));

    // Environmental bonuses
    addBonus("herbalism", 5);
    addBonus("farming", 10);

    // Harvestable resources
    harvestableResource("grain", 20, "/lib/domains/town/obj/grain", 
        "with harvested fields");

    // Domain enhancements
    addBuildingBonus("vegetable garden", "farming", (["capacity": 5]));
    addBuildingBonus("granary", "food storage", (["capacity": 200]));
    addResourceProduction("food", "common", 15);
    addTroopBonus("farmer militia", "morale", 3);
    addHenchmanBonus("farmer", "farming", 12);
    addTradeGood("grain", 25, 300);
}
```

The domain enhancement system allows terrain to become a vital part 
of the larger strategic gameplay, affecting everything from military 
effectiveness to economic prosperity while maintaining the rich 
environmental storytelling that makes each location unique.
