local library = loadstring(game:HttpGet("https://raw.githubusercontent.com/bobbbb-b/nyulabutlowbudget/main/Lib%20(1).txt"))()

-- Gui to Lua
-- Version: 3.2

-- Instances:

local ScreenGui = Instance.new("ScreenGui")
local Frame = Instance.new("Frame")
local TextButton = Instance.new("TextButton")
local UITextSizeConstraint = Instance.new("UITextSizeConstraint")

--Properties:

ScreenGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
ScreenGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling

Frame.Parent = ScreenGui
Frame.BackgroundColor3 = Color3.fromRGB(252, 255, 0)
Frame.BackgroundTransparency = 0
Frame.Position = UDim2.new(1, -120, 0, 0)
Frame.Size = UDim2.new(0, 100, 0, 50)

TextButton.Parent = Frame
TextButton.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
TextButton.BackgroundTransparency = 1.000
TextButton.Size = UDim2.new(1, 0, 1, 0)
TextButton.Font = Enum.Font.SourceSans
TextButton.Text = "Nebula"
TextButton.TextColor3 = Color3.fromRGB(0, 0, 0)
TextButton.TextScaled = true
TextButton.TextSize = 30
TextButton.TextStrokeColor3 = Color3.fromRGB(255, 255, 255)
TextButton.TextStrokeTransparency = 0.000
TextButton.TextWrapped = true
TextButton.MouseButton1Down:Connect(function()
library:ToggleMenu()
end)

UITextSizeConstraint.Parent = TextButton
UITextSizeConstraint.MaxTextSize = 30

local player = game.Players.LocalPlayer

-- Function to show the GUI when the character respawns
local function onCharacterAdded(character)
    ScreenGui.Parent = player.PlayerGui
end

-- Function to connect character respawn event
local function connectCharacterAdded()
    player.CharacterAdded:Connect(onCharacterAdded)
end

-- Connect the CharacterAdded event
connectCharacterAdded()

-- Keep the GUI visible when the character dies
player.CharacterRemoving:Connect(function()
    ScreenGui.Parent = nil
end) 

local hitsounds = {
    {name = "bell.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/bell.wav?raw=true"},
    {name = "bepis.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/bepis.wav?raw=true"},
    {name = "bubble.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/bubble.wav?raw=true"},
    {name = "cock.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/cock.wav?raw=true"},
    {name = "cod.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/cod.wav?raw=true"},
    {name = "fatality.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/fatality.wav?raw=true"},
    {name = "phonk.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/phonk.wav?raw=true"},
    {name = "sparkle.wav", url = "https://github.com/nyulachan/nyula/blob/main/Sounds/sparkle.wav?raw=true"}
}

if not isfolder("hitsounds") then
    makefolder("hitsounds")
end

for _, sound in pairs(hitsounds) do
    local path = "hitsounds" .. "/" .. sound.name
    if not isfile(path) then
        writefile(path, game:HttpGet(sound.url))
    end
end

local woah = library:New("mec mec, nebula.cc [for mob]")
local misc = woah:Tab("Combat")
local gaey = woah:Tab("Mods")
local visu = woah:Tab("Visualization")
local braeuh = woah:Tab("Configs")

local Haka = gaey:MSector("Mods", "Left")
local Lalaka = Haka:Tab("Local")
local Halaka = Haka:Tab("Anti")
local Galala = Haka:Tab("CSync")
local Bakala = Haka:Tab("Fun")

Lalaka:Element("Button", "CFrame Speed", {}, function() 
-- Initial values
getgenv().Speed = false
getgenv().SpeedAmount = 2
-- Create a basic GUI
local ScreenGui = Instance.new("ScreenGui")
ScreenGui.Parent = game.Players.LocalPlayer:WaitForChild("PlayerGui")
ScreenGui.ResetOnSpawn = false

local ToggleButton = Instance.new("TextButton")
ToggleButton.Text = "Toggle Speed"
ToggleButton.Parent = ScreenGui
ToggleButton.BackgroundTransparency = 0.5
ToggleButton.BorderSizePixel = 0
ToggleButton.Position = UDim2.new(1, -120, 0, 55) -- Adjusted the position to top right corner
ToggleButton.Size = UDim2.new(0, 100, 0, 18)
ToggleButton.BackgroundColor3 = Color3.fromRGB(48, 113, 169)
ToggleButton.TextColor3 = Color3.fromRGB(255, 255, 255)

local UICorner = Instance.new("UICorner")
UICorner.Parent = ToggleButton

local function onButtonClicked()
    getgenv().Speed = not getgenv().Speed
end

ToggleButton.MouseButton1Click:Connect(onButtonClicked)

-- Your existing code modified for the GUI
game:GetService("RunService").Stepped:Connect(function()
    if getgenv().Speed then
        local lPlr = game:GetService("Players").LocalPlayer
        lPlr.Character.HumanoidRootPart.CFrame = lPlr.Character.HumanoidRootPart.CFrame + lPlr.Character.Humanoid.MoveDirection * getgenv().SpeedAmount
    end
end)
end)

Lalaka:Element("TextBox", "SpeedaAmount", {placeholder = "Prediction"})

Lalaka:Element("Button", "Save", {}, function() 
getgenv().SpeedAmount = values.Haka.Lalaka.SpeedaAmount.Text
end)

--// TARGET LOCK

local Jaja = misc:MSector("Target Lock", "Left")
local GAGEJ = Jaja:Tab("Main")


GAGEJ:Element("Button", "Load Target", {}, function() 
getgenv().getgenv().Settings = {
    NyulaRemake = {
        Enabled = true,
        PREDICTION = 0.14284,
        JUMPPREDICTION = 0.1184,
        DOT = true,
        AIRSHOT = false,
        NOTIF = true,
        AUTOPRED = false,
        FOV = math.huge,
        RESOLVER = false,
        LOCKTYPE = "Index",
        Resolver = {
              Enabled = false,
              Type = "None",
        },
        OnHit = {
             Enabled = false,
             Hitchams = {
                   Enabled = false,
                   Color = Color3.fromRGB(255,255,255),
             },
            Hitsounds = {
                  Enabled = false,
                  Sound = "hitsounds/sparkle.wav",
            },
        }
    }
}

local SelectedPart = "HumanoidRootPart" --// LowerTorso, UpperTorso, Head
local Prediction = true

--// Change Prediction,  AutoPrediction Must Be Off

    local AnchorCount = 0
    local MaxAnchor = 50
 
    local CC = game:GetService"Workspace".CurrentCamera
    local Plr;
    local enabled = false
    
    local mouse = game.Players.LocalPlayer:GetMouse()
    local placemarker = Instance.new("Part", game.Workspace)
 
    function makemarker(Parent, Adornee, Color, Size, Size2)
        local e = Instance.new("BillboardGui", Parent)
        e.Name = "PP"
        e.Adornee = Adornee
        e.Size = UDim2.new(Size, Size2, Size, Size2)
        e.AlwaysOnTop = getgenv().Settings.NyulaRemake.DOT
        local a = Instance.new("Frame", e)
        if getgenv().Settings.NyulaRemake.DOT == true then
        a.Size = UDim2.new(1, 1, 1, 1)
        else
        a.Size = UDim2.new(0, 0, 0, 0)
        end
        if getgenv().Settings.NyulaRemake.DOT == true then
        a.Transparency = 0
        a.BackgroundTransparency = 0
        else
        a.Transparency = 1
        a.BackgroundTransparency = 1
        end
        a.BackgroundColor3 = Color
        local g = Instance.new("UICorner", a)
        if getgenv().Settings.NyulaRemake.DOT == false then
        g.CornerRadius = UDim.new(1, 1)
        else
        g.CornerRadius = UDim.new(1, 1) 
        end
        return(e)
    end
 
 
    local data = game.Players:GetPlayers()
    function noob(player)
        local character
        repeat wait() until player.Character
        local handler = makemarker(guimain, player.Character:WaitForChild(SelectedPart), Color3.fromRGB(107, 184, 255), 0.3, 3)
        handler.Name = player.Name
        player.CharacterAdded:connect(function(Char) handler.Adornee = Char:WaitForChild(SelectedPart) end)
 
 
        spawn(function()
            while wait() do
                if player.Character then
                end
            end
        end)
    end
 
    for i = 1, #data do
        if data[i] ~= game.Players.LocalPlayer then
            noob(data[i])
        end
    end
 
    game.Players.PlayerAdded:connect(function(Player)
        noob(Player)
    end)
 
    spawn(function()
        placemarker.Anchored = true
        placemarker.CanCollide = false
        if getgenv().Settings.NyulaRemake.DOT == true then
        placemarker.Size = Vector3.new(0, 0, 0)
        else
        placemarker.Size = Vector3.new(0, 0, 0)
        end
        placemarker.Transparency = 0.75
        if getgenv().Settings.NyulaRemake.DOT then
        makemarker(placemarker, placemarker, Color3.fromRGB(48, 113, 169), 1, 0)
        end
    end)
 
    local Tool = Instance.new("Tool")
Tool.RequiresHandle = false
Tool.Name = "Nebula"
Tool.Parent = game.Players.LocalPlayer.Backpack

local player = game.Players.LocalPlayer

local function connectCharacterAdded()
    player.CharacterAdded:Connect(onCharacterAdded)
end

connectCharacterAdded()

player.CharacterRemoving:Connect(function()
    Tool.Parent = game.Players.LocalPlayer.Backpack
end)

Tool.Activated:Connect(function()
if getgenv().Settings.NyulaRemake.Enabled then
            if enabled == true then
                enabled = false
                if getgenv().Settings.NyulaRemake.NOTIF == true then
                    Plr = getClosestPlayerToCursor()
         las.Parent = nil       game.StarterGui:SetCore("SendNotification", {
                    Title = "Nebula.cc";
                    Text = "Unlocked",
                    Duration = 5
                })
            end
            else
                Plr = getClosestPlayerToCursor()
                enabled = true
local char = Plr.Character or Plr.CharacterAdded:Wait()
local hum = char:FindFirstChild("Humanoid")
local oldHealth = hum.Health

function hitchams(gay) 
    if currentClone then
        currentClone:Destroy()
    end

    gay.Character.Archivable = true
    local Clone = gay.Character:Clone()           
    for _, Obj in next, Clone:GetDescendants() do
        if Obj.Name == "HumanoidRootPart" or Obj:IsA("Humanoid") or Obj:IsA("LocalScript") or Obj:IsA("Script") or Obj:IsA("Decal") then
            Obj:Destroy()
        elseif Obj:IsA("BasePart") or Obj:IsA("MeshPart") or Obj:IsA("Part") then
            if Obj.Transparency == 1 then
                Obj:Destroy()
            else
                Obj.CanCollide = false
                Obj.Anchored = true
                Obj.Material = Enum.Material.ForceField
                Obj.Color = getgenv().Settings.NyulaRemake.OnHit.Hitchams.Color
                Obj.Transparency = 0
                Obj.Size = Obj.Size + Vector3.new(0.03, 0.03, 0.03)
            end
        end
    end
    Clone.Parent = workspace
    currentClone = Clone
    local start = tick()
    local connection
    connection = game:GetService("RunService").Heartbeat:Connect(function()
        if tick() - start >= 3 then
            connection:Disconnect() 
            Clone:Destroy()
            currentClone = nil
        end
    end)
end

hum.HealthChanged:Connect(function(newHealth)

    if newHealth < oldHealth then
if getgenv().Settings.NyulaRemake.OnHit.Hitsounds.Enabled then
        print("niggas")
                    local las = Instance.new("Sound")
                    las.Name = "a"
                    las.Volume = 1
                    las.SoundId = getcustomasset(getgenv().Settings.NyulaRemake.OnHit.Hitsounds.Sound)
                    las.Parent = game:GetService("SoundService")
                    las.Playing = true
    end
if getgenv().Settings.NyulaRemake.OnHit.Hitchams.Enabled then
hitchams(Plr)
end
local oldHealth = newHealth
end
end)
                if getgenv().Settings.NyulaRemake.NOTIF == true then
 
                    game.StarterGui:SetCore("SendNotification", {
                        Title = "nebula.cc";
                        Text = "Target: "..tostring(Plr.Character.Humanoid.DisplayName),
                        Duration = 5
                    })
 
                end
            end
        end
    end)
 
 
 
    function getClosestPlayerToCursor()
        local closestPlayer
        local shortestDistance = getgenv().Settings.NyulaRemake.FOV
 
        for i, v in pairs(game.Players:GetPlayers()) do
            if v ~= game.Players.LocalPlayer and v.Character and v.Character:FindFirstChild("Humanoid") and v.Character.Humanoid.Health ~= 0 and v.Character:FindFirstChild("HumanoidRootPart") then
                local pos = CC:WorldToViewportPoint(v.Character.PrimaryPart.Position)
                local magnitude = (Vector2.new(pos.X, pos.Y) - Vector2.new(mouse.X, mouse.Y)).magnitude
                if magnitude < shortestDistance then
                    closestPlayer = v
                    shortestDistance = magnitude
                end
            end
        end
        return closestPlayer
    end
 
    local pingvalue = nil;
    local split = nil;
    local ping = nil;

local LocalHL = Instance.new("Highlight") 
    game:GetService"RunService".Stepped:connect(function()
        if enabled and Plr.Character ~= nil and Plr.Character:FindFirstChild("HumanoidRootPart") then
            placemarker.CFrame = CFrame.new(Plr.Character.HumanoidRootPart.Position+Vector3.new(Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.X*getgenv().Settings.NyulaRemake.PREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Y*getgenv().Settings.NyulaRemake.JUMPPREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Z*getgenv().Settings.NyulaRemake.PREDICTION))         
LocalHL.Parent = Plr.Character
LocalHL.FillTransparency = 0.2
LocalHL.FillColor = Color3.fromRGB(48, 113, 169)
LocalHL.OutlineColor = Color3.fromRGB(0,0,0)
        else
            placemarker.CFrame = CFrame.new(0, 9999, 0)
          LocalHL.Parent = nil
        end
if getgenv().Settings.NyulaRemake.AUTOPRED == true then
pingvalue = game:GetService("Stats").Network.ServerStatsItem["Data Ping"]:GetValueString()
             split = string.split(pingvalue,'(')
             ping = tonumber(split[1])
 if ping <200 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.197343243234332
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 170 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.164713
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 160 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.16142
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 150 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.157041
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 140 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.154313
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 130 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.151692
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 120 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.14917
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 110 then
        getgenv().Settings.NyulaRemake.PREDICTION = 0.146
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    elseif ping < 100 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.142987
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
 elseif ping < 80 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.140340
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
 elseif ping < 70 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.12633
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
 elseif ping < 65 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.1274236
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
 elseif ping < 50 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.13644
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
 elseif ping < 30 then
  getgenv().Settings.NyulaRemake.PREDICTION = 0.11452476
getgenv().Settings.NyulaRemake.JUMPPREDICTION = tostring(ping/1500)
    end
end
if getgenv().Settings.NyulaRemake.Resolver.Enabled then
if getgenv().Settings.NyulaRemake.Resolver.Type == "Delta Time" then
print("wsg")
end
if getgenv().Settings.NyulaRemake.Resolver.Type == "Recalculator" then
print("wsg")
end
if getgenv().Settings.NyulaRemake.Resolver.Type == "No Y Velocity" then
print("wsg")
end
end
    end)
 
    local mt = getrawmetatable(game)
    local old = mt.__namecall
    setreadonly(mt, false)
    mt.__namecall = newcclosure(function(...)
        local args = {...}
        local vap = {"UpdateMousePos", "GetMousePos", "MousePos", "MOUSE", "MousePosUpdate"}
        if enabled and getnamecallmethod() == "FireServer" and table.find(vap, args[2]) and getgenv().Settings.NyulaRemake.Enabled and Plr.Character ~= nil and getgenv().Settings.NyulaRemake.LOCKTYPE == "Namecall" then
            -- args[3] = Plr.Character.HumanoidRootPart.Position+(Plr.Character.HumanoidRootPart.Velocity*accomidationfactor)
            --[[
            if getgenv().Settings.NyulaRemake.AIRSHOT == true then
                if game.Workspace.Players[Plr.Name].Humanoid:GetState() == Enum.HumanoidStateType.Freefall then -- Plr.Character:WaitForChild("Humanoid"):GetState() == Enum.HumanoidStateType.Freefall
 
                    --// Airshot
                    args[3] = Plr.Character.LeftFoot.Position+(Plr.Character.LeftFoot.Velocity*PredictionValue)
 
                else
                    args[3] = Plr.Character.HumanoidRootPart.Position+(Plr.Character.HumanoidRootPart.Velocity*PredictionValue)
 
                end
            else
                    args[3] = Plr.Character.HumanoidRootPart.Position+(Plr.Character.HumanoidRootPart.Velocity*PredictionValue)
            end
            ]]
            if Prediction == true then
 
            args[3] = Plr.Character.HumanoidRootPart.Position+Vector3.new(Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.X*getgenv().Settings.NyulaRemake.PREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Y*getgenv().Settings.NyulaRemake.JUMPPREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Z*getgenv().Settings.NyulaRemake.PREDICTION)
 
            else
 
            args[3] = Plr.Character[SelectedPart].Position
 
            end
 
            return old(unpack(args))
        end
        return old(...)
    end)
 
    game:GetService("RunService").RenderStepped:Connect(function()
        if getgenv().Settings.NyulaRemake.RESOVLER == true and Plr.Character ~= nil and enabled and getgenv().Settings.NyulaRemake.Enabled then
        if getgenv().Settings.NyulaRemake.AIRSHOT == true and enabled and Plr.Character ~= nil then
 
            if game.Workspace.Players[Plr.Name].Humanoid:GetState() == Enum.HumanoidStateType.Freefall then -- Plr.Character:WaitForChild("Humanoid"):GetState() == Enum.HumanoidStateType.Freefall
 
                --// Airshot
 
                --// Anchor Check
 
                if Plr.Character ~= nil and Plr.Character.HumanoidRootPart.Anchored == true then
                    AnchorCount = AnchorCount + 1
                    if AnchorCount >= MaxAnchor then
                        Prediction = false
                        wait(2)
                        AnchorCount = 0;
                    end
                else
                    Prediction = true
                    AnchorCount = 0;
                end
 
                SelectedPart = "LeftFoot"
 
            else
                --// Anchor Check
 
                if Plr.Character ~= nil and Plr.Character.HumanoidRootPart.Anchored == true then
                    AnchorCount = AnchorCount + 1
                    if AnchorCount >= MaxAnchor then
                        Prediction = false
                        wait(2)
                        AnchorCount = 0;
                    end
                else
                    Prediction = true
                    AnchorCount = 0;
                end
 
                SelectedPart = "HumanoidRootPart"
 
            end
            else
 
                --// Anchor Check
 
                if Plr.Character ~= nil and Plr.Character.HumanoidRootPart.Anchored == true then
                    AnchorCount = AnchorCount + 1
                    if AnchorCount >= MaxAnchor then
                        Prediction = false
                        wait(2)
                        AnchorCount = 0;
                    end
                else
                    Prediction = true
                    AnchorCount = 0;
                end
 
                SelectedPart = "HumanoidRootPart"
            end
 
        else
                SelectedPart = "HumanoidRootPart"
        end
    end)

local Hooks = {}
local Client = game.Players.LocalPlayer

Hooks[1] = hookmetamethod(Client:GetMouse(), "__index", newcclosure(function(self, index)
    if index == "Hit" and getgenv().Settings.NyulaRemake.LOCKTYPE == "Index" and enabled and Plr.Character ~= nil and getgenv().Settings.NyulaRemake.Enabled then
            local position = CFrame.new(Plr.Character.HumanoidRootPart.Position+Vector3.new(Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.X*getgenv().Settings.NyulaRemake.PREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Y*getgenv().Settings.NyulaRemake.JUMPPREDICTION,Plr.Character.HumanoidRootPart.AssemblyLinearVelocity.Z*getgenv().Settings.NyulaRemake.PREDICTION))
            return position
        
    end
    return Hooks[1](self, index)
end))

end)

GAGEJ:Element("Dropdown", "Aim Type", {options = {"Index", "Namecall"}}, function(tbjl)
getgenv().Settings.NyulaRemake.LOCKTYPE = tbjl.Dropdown
end)

GAGEJ:Element("TextBox", "Prediction", {placeholder = "Prediction"})

GAGEJ:Element("Button", "Save", {}, function() 
getgenv().Settings.NyulaRemake.PREDICTION = values.Jaja.GAGEJ.Prediction.Text
end)

GAGEJ:Element("TextBox", "JumpPrediction", {placeholder = "Jump Prediction"})

GAGEJ:Element("Button", "Save", {}, function() getgenv().Settings.NyulaRemake.JUMPPREDICTION = values.Jaja.GAGEJ.JumpPrediction.Text
end)

GAGEJ:Element("Toggle", "Auto Prediction", nil, function(tbll)
getgenv().Settings.NyulaRemake.AUTOPRED = tbll.Toggle
end)

--// ONHIT
local configs = Jaja:Tab("On Hit")

configs:Element("Toggle", "Hitcham", nil, function(tbll)
getgenv().Settings.NyulaRemake.OnHit.Hitchams.Enabled = tbll.Toggle
end)

configs:Element("Toggle", "Hitsound", nil, function(tbll)
getgenv().Settings.NyulaRemake.OnHit.Hitsounds.Enabled = tbll.Toggle
end)

--// MODS
local mamamoblue = Jaja:Tab("Mods")

--// RESOLVERS
local mamamored = Jaja:Tab("Resolvers")

mamamored:Element("Toggle", "Enabled", nil, function(bruh)
print(bruh.Toggle)
end)

mamamored:Element("Dropdown", "Type", {options = {"None", "Delta Time", "Recalculator", "No Y Velocity"}}, function(tbjol)
print(tbjol.Dropdown)
end)
