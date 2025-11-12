local function place_factory_on_market(market, city, resource, amount)
    local factory = core.create_factory(city, recipes[resource], amount)
    core.attach_market(market, factory)
    core.set_power_consumption(factory, 1000, 60)
    -- Enable production next
    core.add_production(factory)
    return factory
end

generators:insert({
    name = "default",
    civ_init = function()
    end,
    universe_gen = function()
<<<<<<< HEAD
=======
        print("Generating star system")
        for x = 1, 1000, 1 do
            local sys = create_star_system()
        
            -- Set orbit
            local star_count = 1
        
            -- Add star
            local star = add_star(sys)
            set_orbit(star, 0.001, 0, 0, 0)
            set_radius(star, random(1500000, 3000000))
        
            local planet_count = get_planet_count()
            local distance = random(1, 100)/100
            local first = random(1, 100)/100
            for planet_id = 0, planet_count, 1 do
                -- Create planets
                planet_entity = add_planet(sys)
        
                -- Set orbits
                -- Distance can be modeled after a log graph, then convert to km because our regression was based off AU
                set_planet_orbit(planet_entity, planet_id, distance, first)
        
                local radius = random(1000, 30000)
                set_radius(planet_entity, radius)
                -- Set planet type
                -- Set planet terrain
                -- Esh, we'll deal with that later
                -- As you go further from the center, make it more likely that it is a gas planet
            end
        end
        
        for _, civ in pairs(civilizations) do
            print("Making civilization")
            -- Set planets
            local sys = create_star_system()
        
            -- Set orbit
            local star_count = 1
        
            -- Add star
            local star = add_star(sys)
            set_orbit(star, 0.001, 0, 0, 0)
            set_radius(star, random(1500000, 3000000))
        
            local planet_count = random_normal_int(7, 2)
            if planet_count < 0 then
                planet_count = 0
            end
            local distance = random(1, 100)/100
            local first = random(1, 100)/100
            for planet_id = 0, planet_count, 1 do
                -- Create planets
                planet_entity = add_planet(sys)
        
                -- Set orbits
                -- Distance can be modeled after a log graph, then convert to km because our regression was based off AU
                set_planet_orbit(planet_entity, planet_id, distance, first)
                set_name(planet_entity, ""..planet_entity)
                local radius = random(1000, 30000)
                set_radius(planet_entity, radius)
                create_terrain(planet_entity, random(0, 10000000))
                -- Set planet type
                -- Set planet terrain
                -- Esh, we'll deal with that later
                -- As you go further from the center, make it more likely that it is a gas planet
        
                if planet_id == 2 then
                    -- Set as civ home planet
                    set_civilization_planet(civ, planet_entity)
                    set_name(planet_entity, "Earting")
                    set_name(create_ship(civ, planet_entity, sys), "Earting Ship")
                end
            end
        end
>>>>>>> pr_4
    end,
    planets = function(civ_id)
        -- TODO(EhWhoAmI): Add earth cities and earth
        local planet = core.get_civilization_planet(civ_id)
        if core.is_player(civ_id) then
            print("Initializing player")
            core.set_name(civ_id, "Player Civilization")
        end

        -- Add tech
        core.add_tech_progress(civ_id)

<<<<<<< HEAD
        core.complete_technology(civ_id, technologies["steel_forging"])
        core.complete_technology(civ_id, technologies["consumer_good_manufacturing"])
        core.complete_technology(civ_id, technologies["concrete_manufacturing"])
        core.complete_technology(civ_id, technologies["basic_mining"])
        core.research_technology(civ_id, technologies["blank_research"])
        core.add_potential_tech(civ_id, technologies["temp_research"])
=======
        -- Add city
        local city_count = random(300, 500)
        for index = 0, city_count, 1 do
            local city = add_planet_settlement(planet, random(-90, 90) , random(-180, 180))
            set_name(city, "City ".. index)
            local pop_unit = add_population_segment(city, random_normal_int(50000000, 2000000)) -- 100 million
            attach_market(market, pop_unit)
            set_resource_consume(pop_unit, goods["consumer_good"], 1750)
            -- Add industry
            create_industries(city)
            attach_market(market, create_factory(city, recipes["steel_forging"], 1500))
            -- Add various factories
            attach_market(market, create_factory(city, recipes["consumer_good_manufacturing"], 1000))
            attach_market(market, create_factory(city, recipes["concrete_manufacturing"], 300))
            attach_market(market, create_mine(city, goods["copper"], 1000, 1))
            attach_market(market, create_mine(city, goods["aluminium"], 1000, 1))
            attach_market(market, create_mine(city, goods["stone"], 1000, 1))
            attach_market(market, create_mine(city, goods["iron"], 10000, 1))
        end
>>>>>>> pr_28
    end
})
