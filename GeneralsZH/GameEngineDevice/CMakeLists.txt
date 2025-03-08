# Copyright 2025 Open Hour Contributors.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
target_sources(GeneralsZH PRIVATE
        # W3DDevice/Common
        Source/W3DDevice/Common/System/W3DFunctionLexicon.cpp
        Source/W3DDevice/Common/System/W3DRadar.cpp

        Source/W3DDevice/Common/Thing/W3DModuleFactory.cpp
        Source/W3DDevice/Common/Thing/W3DThingFactory.cpp

        Source/W3DDevice/Common/W3DConvert.cpp

        # W3DDevice/GameClient
        Source/W3DDevice/GameClient/Drawable/Draw/W3DDebrisDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DDefaultDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DDependencyModelDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DLaserDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DModelDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DOverlordAircraftDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DOverlordTankDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DOverlordTruckDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DPoliceCarDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DProjectileStreamDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DPropDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DRopeDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DScienceModelDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DSupplyDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DTankDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DTankTruckDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DTracerDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DTreeDraw.cpp
        Source/W3DDevice/GameClient/Drawable/Draw/W3DTruckDraw.cpp

        Source/W3DDevice/GameClient/GUI/Gadget/W3DCheckBox.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DComboBox.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DHorizontalSlider.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DListBox.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DProgressBar.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DPushButton.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DRadioButton.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DStaticText.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DTabControl.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DTextEntry.cpp
        Source/W3DDevice/GameClient/GUI/Gadget/W3DVerticalSlider.cpp

        Source/W3DDevice/GameClient/GUI/GUICallbacks/W3DControlBar.cpp
        Source/W3DDevice/GameClient/GUI/GUICallbacks/W3DMainMenu.cpp
        Source/W3DDevice/GameClient/GUI/GUICallbacks/W3DMOTD.cpp

        Source/W3DDevice/GameClient/GUI/W3DGameFont.cpp
        Source/W3DDevice/GameClient/GUI/W3DGameWindow.cpp
        Source/W3DDevice/GameClient/GUI/W3DGameWindowManager.cpp

        Source/W3DDevice/GameClient/Shadow/W3DBufferManager.cpp
        Source/W3DDevice/GameClient/Shadow/W3DProjectedShadow.cpp
        Source/W3DDevice/GameClient/Shadow/W3DShadow.cpp
        Source/W3DDevice/GameClient/Shadow/W3DVolumetricShadow.cpp

        Source/W3DDevice/GameClient/Water/W3DWater.cpp
        Source/W3DDevice/GameClient/Water/W3DWaterTracks.cpp

        Source/W3DDevice/GameClient/BaseHeightMap.cpp
        Source/W3DDevice/GameClient/camerashakesystem.cpp
        Source/W3DDevice/GameClient/FlatHeightMap.cpp
        Source/W3DDevice/GameClient/HeightMap.cpp
        Source/W3DDevice/GameClient/TerrainTex.cpp
        Source/W3DDevice/GameClient/TileData.cpp
        Source/W3DDevice/GameClient/W3DAssetManager.cpp
        Source/W3DDevice/GameClient/W3DAssetManagerExposed.cpp
        Source/W3DDevice/GameClient/W3DBibBuffer.cpp
        Source/W3DDevice/GameClient/W3DBridgeBuffer.cpp
        Source/W3DDevice/GameClient/W3DCustomEdging.cpp
        Source/W3DDevice/GameClient/W3DDebugDisplay.cpp
        Source/W3DDevice/GameClient/W3DDebugIcons.cpp
        Source/W3DDevice/GameClient/W3DDisplay.cpp
        Source/W3DDevice/GameClient/W3DDisplayString.cpp
        Source/W3DDevice/GameClient/W3DDisplayStringManager.cpp
        Source/W3DDevice/GameClient/W3DDynamicLight.cpp
        Source/W3DDevice/GameClient/W3DFileSystem.cpp
        Source/W3DDevice/GameClient/W3DGameClient.cpp
        Source/W3DDevice/GameClient/W3DGranny.cpp
        Source/W3DDevice/GameClient/W3DInGameUI.cpp
        Source/W3DDevice/GameClient/W3DMouse.cpp
        Source/W3DDevice/GameClient/W3DParticleSys.cpp
        Source/W3DDevice/GameClient/W3DPoly.cpp
        Source/W3DDevice/GameClient/W3DPropBuffer.cpp
        Source/W3DDevice/GameClient/W3DRoadBuffer.cpp
        Source/W3DDevice/GameClient/W3DScene.cpp
        Source/W3DDevice/GameClient/W3DShaderManager.cpp
        Source/W3DDevice/GameClient/W3DShroud.cpp
        Source/W3DDevice/GameClient/W3DSmudge.cpp
        Source/W3DDevice/GameClient/W3DSnow.cpp
        Source/W3DDevice/GameClient/W3DStatusCircle.cpp
        Source/W3DDevice/GameClient/W3DTerrainBackground.cpp
        Source/W3DDevice/GameClient/W3DTerrainTracks.cpp
        Source/W3DDevice/GameClient/W3DTerrainVisual.cpp
        Source/W3DDevice/GameClient/W3DTreeBuffer.cpp
        Source/W3DDevice/GameClient/W3DVideoBuffer.cpp
        Source/W3DDevice/GameClient/W3DView.cpp
        Source/W3DDevice/GameClient/W3dWaypointBuffer.cpp
        Source/W3DDevice/GameClient/WorldHeightMap.cpp

        # W3DDevice/GameLogic
        Source/W3DDevice/GameLogic/W3DGameLogic.cpp
        Source/W3DDevice/GameLogic/W3DGhostObject.cpp
        Source/W3DDevice/GameLogic/W3DTerrainLogic.cpp

        # Win32Device/Common
        Source/Win32Device/Common/Win32BIGFile.cpp
        Source/Win32Device/Common/Win32BIGFileSystem.cpp
        Source/Win32Device/Common/Win32CDManager.cpp
        Source/Win32Device/Common/Win32GameEngine.cpp
        Source/Win32Device/Common/Win32LocalFile.cpp
        Source/Win32Device/Common/Win32LocalFileSystem.cpp
        Source/Win32Device/Common/Win32OSDisplay.cpp

        # Win32Device/GameClient
        Source/Win32Device/GameClient/Win32DIKeyboard.cpp
        Source/Win32Device/GameClient/Win32DIMouse.cpp
        Source/Win32Device/GameClient/Win32Mouse.cpp)

target_include_directories(GeneralsZH PRIVATE
        Include)