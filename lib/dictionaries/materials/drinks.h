//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef drinks_h
#define drinks_h

protected mapping drinks =
([
    "pilsner beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "light malted barley": 2,
            "noble hops": 1,
            "lager yeast": 1 
        ]),
        "default description": "A golden, crisp beer with a clean taste and light body. Noble hops "
            "provide a subtle floral aroma and refreshing bitterness that balances "
            "perfectly with the light malt sweetness.",
        "base experience": 5,
    ]),
    "bock beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "munich malted barley": 2,
            "cascade hops": 1,
            "lager yeast": 1 
        ]),
        "default description": "A robust dark amber lager with a rich, toasty malt character. The "
            "rich malt provides notes of caramel and bread crust, while cascade "
            "hops add a gentle citrus touch to balance the sweetness.",
        "base experience": 5,
    ]),
    "kolsche beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "light malted barley": 2,
            "saaz hops": 1,
            "lager yeast": 1 
        ]),
        "default description": "A bright, straw-colored beer with brilliant clarity. This delicate "
            "brew offers subtle fruit notes, a gentle spicy hop character from the "
            "saaz hops, and finishes crisp and clean.",
        "base experience": 5,
    ]),
    "amber ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "red malted barley": 2,
            "hallertau hops": 1,
            "ale yeast": 1 
        ]),
        "default description": "A copper-colored ale with a pleasant malt-forward flavor profile. "
            "Red malted barley gives it notes of toffee and toasted bread, while "
            "the hallertau hops provide a subtle herbal balance.",
        "base experience": 5,
    ]),
    "milk stout beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 5]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "cascade hops": 1,
            "milk": 1,
            "ale yeast": 1 
        ]),
        "default description": "A silky-smooth, dark beer with creamy sweetness from added lactose. "
            "Complex flavors of chocolate, coffee, and dark fruits blend with a "
            "velvety mouthfeel and subtle cascade hop bitterness.",
        "base experience": 5,
    ]),
    "porter beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "galena hops": 1,
            "ale yeast": 1 
        ]),
        "default description": "A dark brown beer with ruby highlights when held to light. Rich "
            "flavors of dark chocolate, coffee, and light smoke balance with "
            "subtle berry notes and a clean, dry finish.",
        "base experience": 5,
    ]),
    "stout beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 3,
            "cascade hops": 1,
            "ale yeast": 1 
        ]),
        "default description": "A pitch-black beer with a thick, creamy tan head. Strong roasted "
            "flavors dominate with notes of espresso, bitter chocolate, and "
            "charred toast balanced by subtle cascade hop undertones.",
        "base experience": 5,
    ]),
    "black pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "dark malted barley": 2,
            "citra hops": 3,
            "ale yeast": 1 
        ]),
        "default description": "A contradictory brew that looks like a stout but tastes like a "
            "pale ale. Dark color with abundant citra hop aroma of tropical fruit "
            "and citrus, light roast notes, and a bright, hoppy finish.",
        "base experience": 5,
    ]),
    "pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 2,
            "citra hops": 2,
            "cascade hops": 1,
            "ale yeast": 1 
        ]),
        "default description": "A golden-amber beer with a fragrant citrus and pine hop aroma. "
            "Balanced malt sweetness supports vibrant flavors of grapefruit, "
            "orange, and subtle tropical notes from the generous hop additions.",
        "base experience": 5,
    ]),
    "dubbel beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "goldings hops": 1,
            "abbey yeast": 1 
        ]),
        "default description": "A reddish-brown ale with rich flavors of dark fruit, "
            "caramel, and brown sugar. The abbey yeast contributes subtle spicy "
            "notes of clove and pepper with minimal hop presence.",
        "base experience": 5,
    ]),
    "trippel beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "candied sugar": 1,
            "hallertau hops": 1,
            "abbey yeast": 1 
        ]),
        "default description": "A golden Belgian-style ale with surprising strength hidden behind "
            "its elegant appearance. Complex flavors of pear, apple, and honey "
            "blend with spicy yeast notes and a warming alcohol finish.",
        "base experience": 5,
    ]),
    "quad beer":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 3]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 4,
            "goldings hops": 1,
            "abbey yeast": 1 
        ]),
        "default description": "A deep mahogany Belgian-style ale of profound complexity and "
            "strength. Rich layers of dark fruit, caramel, fig, raisin, and "
            "molasses mingle with subtle chocolate and spice notes.",
        "base experience": 5,
    ]),
    "cherry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "cherry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "default description": "A reddish-pink spontaneously fermented beer with a delicate "
            "balance of sweet and tart cherry flavors. The wild yeast provides "
            "funky, earthy undertones that complement the fruit beautifully.",
        "base experience": 5,
    ]),
    "raspberry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "raspberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "default description": "A vibrant pink spontaneously fermented beer that showcases bright "
            "raspberry flavor. Sweet berry notes lead to a pleasantly tart finish, "
            "complemented by the wild yeast's complex barnyard character.",
        "base experience": 5,
    ]),
    "blackberry lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "blackberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "default description": "A deep purple spontaneously fermented beer with rich blackberry "
            "flavor and aroma. Jammy fruit notes give way to wild yeast funk and "
            "a pleasant acidity that creates a beautifully balanced drink.",
        "base experience": 5,
    ]),
    "serendipitous lambic ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 8]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "cherry": 2,
            "cranberry": 1,
            "apple": 1,
            "malted wheat": 3,
            "saaz hops": 1,
            "wild yeast": 1
        ]),
        "default description": "A complex, ruddy-hued spontaneously fermented beer featuring a "
            "masterful blend of fruits. Cherry, cranberry, and apple harmonize "
            "with earthy wild yeast notes in this sophisticated lambic.",
        "base experience": 5,
    ]),
    "dubbel pale ale":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "malted barley": 3,
            "citra hops": 2,
            "abbey yeast": 1 
        ]),
        "default description": "A hybrid style that marries a dubbel's maltiness with "
            "fruity hop character. Amber-colored with rich caramel notes "
            "complemented by bright citrus and tropical fruit hop flavors.",
        "base experience": 5,
    ]),
    "blueberry lager":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 6]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "blueberry": 4,
            "malted wheat": 3,
            "saaz hops": 1,
            "abbey yeast": 1 
        ]),
        "default description": "A light purple-tinged lager infused with fresh blueberry flavor. "
            "Crisp and refreshing with subtle sweetness, delicate berry aroma, "
            "and a clean finish that highlights the fruit's natural character.",
        "base experience": 5,
    ]),
    "brandy barrel aged weissenbock":([
        "type": "beer",
        "crafting prerequisites": ([
            "/lib/instances/research/crafting/drinks/brewBeer.c":(["type":"research"]),
            "brewing": (["type":"skill", "value": 10]),
        ]),        
        "crafting materials": ([
            "water": 5,
            "brandy barrel": 1,
            "munich malted barley": 2,
            "dark malted barley": 2,
            "cascade hops": 1,
            "abbey yeast": 1 
        ]),
        "default description": "A sophisticated dark wheat beer aged in brandy barrels. Complex "
            "flavors of dark fruit, vanilla, oak, and warming spirit notes "
            "complement the rich malt base in this magnificent brew.",
        "base experience": 5,
    ])
]);

#endif
