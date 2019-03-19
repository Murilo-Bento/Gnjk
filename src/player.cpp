#include "player.hpp"

Player::Player() {
  m_d = STILL;
  last_m_d = STILL;
  f_p = RIGHT;
  m_i = 0;
}

Player::Player(sf::Texture const &texture, sf::Vector2f position)
    : GameObject(texture, sf::Vector2i(32, 32)),
      AnimatedEntity(sf::Vector2i(0, 64), sf::Vector2i(0, 64), 10) {
  m_d = STILL;
  last_m_d = STILL;
  f_p = RIGHT;
  m_i = 0;
  set_sprite_position(position);
}

void Player::animate() {
  if (movement.x > 0)
    apply_animation_by_row(this, 0);
  else if (movement.x < 0)
    apply_animation_by_row(this, 1);
  else
    f_p == RIGHT ? configure_sprite_rect(0, 0) : configure_sprite_rect(0, 32);
}

void Player::jump(float delta_time) {
  movement.y = -5;
  on_ground = false;
}

void Player::apply_gravity(float delta_time) {
  if (get_sprite_position().y < 300)
    movement.y += 10 * delta_time;
  else {
    movement.y = 0;
    on_ground = true;
  }
}

void Player::control_entity(float delta_time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    if (!on_ground && !ac_x_lock)
      m_i += 0.5 * delta_time;
    else
      m_i -= 10 * delta_time;

    if (m_i < 0)
      m_i = 0;
    movement.x = -200 * delta_time - m_i;
    f_p = LEFT;
    m_d = NEGATIVE;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    if (!on_ground && !ac_x_lock)
      m_i += 0.5 * delta_time;
    else
      m_i -= 10 * delta_time;

    if (m_i < 0)
      m_i = 0;
    movement.x = 200 * delta_time + m_i;
    f_p = RIGHT;
    m_d = POSITIVE;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    if (on_ground) {
      if (m_d != last_m_d || !opposite) {
        ac_x_lock = true;
        last_m_d = m_d;
      } else {
        ac_x_lock = false;
        opposite = false;
      }

      jump(delta_time);
    }
  }
}

void Player::move() {
  if (!on_ground)
    if (m_d != last_m_d)
      opposite = true;

  move_sprite(movement);
  movement = sf::Vector2f(0, movement.y);
}

void Player::move(float delta_time) { move_sprite(movement * delta_time); }
