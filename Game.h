//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include "DebugCamera.h"
#include "GridFloor.h"

#include "Ball.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "CollisionMesh.h"
#include "Sprite.h"

#define MAX_ENEMY 10

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

	bool FloorCol(DirectX::SimpleMath::Vector3 objPos, DirectX::SimpleMath::Vector3& ret);

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_keyTracker;

	// マウス
	std::unique_ptr<DirectX::Mouse> m_mouse;

	// コモンステート
	std::unique_ptr<DirectX::CommonStates> m_states;

	//// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	//// スプライトフォント
	std::unique_ptr<DirectX::SpriteFont> m_font;

	// ワールド行列
	DirectX::SimpleMath::Matrix m_world;

	// ビュー行列
	DirectX::SimpleMath::Matrix m_view;

	// 射影行列
	DirectX::SimpleMath::Matrix m_projection;

	// デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugCamera;

	// グリッドの床
	std::unique_ptr<GridFloor>	m_gridFloor;

	// ボール
	std::unique_ptr<Ball>			m_ball;

	// プレイヤー
	std::unique_ptr<Player>			m_player;

	// エネミーアイ
	std::vector<std::unique_ptr<Enemy>>			m_enemyEye;

	Camera m_camera;

	std::unique_ptr<DirectX::Model>	m_floorModel;
	std::unique_ptr<CollisionMesh>	m_floor;



};