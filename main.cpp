#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

constexpr int TILE=20;

struct World{
    std::vector<std::vector<int>> world={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    int score=0;
    int row=world.size();
    int col=world[0].size(); 

    void draw(sf::RenderWindow& window){
        sf::RectangleShape wall(sf::Vector2f(TILE-1, TILE-1)); 
        sf::CircleShape food(float(TILE-18));
        sf::CircleShape pacman(float(TILE-10));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(world[i][j]==1){
                    wall.setFillColor(sf::Color::Blue);
                    wall.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(wall);
                }
                if(world[i][j]==2){
                    food.setFillColor(sf::Color::Yellow);
                    food.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(food);
                } 
            }
        }
    }
};

struct Enemy{ //4 SERA SU IDENTIDAD
    std::vector<std::pair<int,int>> coords;
    enum Color {cero, uno, dos, tres}; //azul, rojo, verde, cyan
    Color color=cero;
    sf::CircleShape enemy;

    Enemy(World& w){ //SINO SE INICIALIZA NADA NO SE DEBE PONER DOS PUNTOS
        coords={{1,6},{1,26},{w.row-4,6},{w.row-4,26}};
        enemy.setRadius(float(TILE-11));
    } 

    void init(World& w, int& i){
        if(i==0) return;
        else if(i==1) color=uno;
        else if(i==2) color=dos;
        else if(i==3) color=tres;

        w.world[coords[i].first][coords[i].second]=4;
    }

    void update(World& w){
        
    }

    void draw(sf::RenderWindow& window, World& w, float alpha){
        if(color==cero){
            enemy.setFillColor(sf::Color::Blue);
            enemy.setPosition({TILE*float(coords[0].second), TILE*float(coords[0].first)});
            window.draw(enemy);
        }else if(color==uno){
            enemy.setFillColor(sf::Color::Red);
            enemy.setPosition({TILE*float(coords[1].second), TILE*float(coords[1].first)});
            window.draw(enemy);
        }else if(color==dos){
            enemy.setFillColor(sf::Color::Yellow);
            enemy.setPosition({TILE*float(coords[2].second), TILE*float(coords[2].first)});
            window.draw(enemy);
        }else if(color==tres){
            enemy.setFillColor(sf::Color::Green);
            enemy.setPosition({TILE*float(coords[3].second), TILE*float(coords[3].first)});
            window.draw(enemy);
        }
    }
};

struct User{ //3 serà su identidad
    int x=10, y=15; //posicion antigua que servirà para el frame suave
    int nx, ny;
    float speed=1.f;
    sf::CircleShape user;

    enum Dir{ LEFT, DOWN, RIGHT, UP};
    Dir dir=RIGHT;

    User(){
        user.setRadius(float(TILE-12));
        user.setPosition(sf::Vector2f(TILE*10, TILE*10));
        user.setFillColor(sf::Color::Yellow);
    }

    void init(World& w){
        w.world[x][y]=3;
    }

    void update(World& w){
        int dx=0, dy=0;
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dy=-1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dy=1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dx=-1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dx=1;

        int tx=x+dx;
        int ty=y+dy;

        //OBSTACULOS
        if(tx<0 || tx>w.row-1 || ty<0 || ty>w.col-1 || w.world[tx][ty]==1){
            nx=x;
            ny=y;
            return;
        }
        
        if(tx==13 && ty>=w.col-1) ty=0;
        else if(tx==13 && ty==0) ty=w.col-1;

        if(tx==14 && ty>=w.col-1) ty=0;
        else if(tx==14 && ty==0) ty=w.col-1;

        if(w.world[nx][ny]==2) w.score++;

        w.world[x][y]=0;
        w.world[nx][ny]=3; //IDENTIDAD DEL USUARIO 3 

        //AQUI ACTUALIZAMOS
        nx=tx;
        ny=ty;
        
        x=nx;
        y=ny;
    }

    void draw(sf::RenderWindow& window, float& alpha){
        float newX=x + (nx-x) * alpha;
        float newY=y + (ny-y) * alpha;

        user.setPosition(sf::Vector2f(newY*TILE, newX*TILE));
        window.draw(user);
    }
};

struct Food{
    //recordar regla de oro:
    //si pacman come, lugar se pone en 0, es decir, lugar vacio
    void init(World& _w){
        for(int i=0; i<_w.row; i++){
            for(int j=0; j<_w.col; j++){
                if(_w.world[i][j]==0) _w.world[i][j]=2;
            }
        }
    }
};

void execute(){
    World _w;
    Food _f;
    User _u;
    std::vector<Enemy> enemies;

    for(int i=0; i<4; i++){
        Enemy e(_w);
        e.init(_w, i);
        enemies.push_back(e);
    }

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(_w.col*TILE),
                static_cast<unsigned>(_w.row*TILE)
        }),
        "PACMAN"
    };

    window.setFramerateLimit(60);

    _f.init(_w);
    _u.init(_w);

    sf::Clock clock;
    float timer=0;
    float delay=0.07;

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close(); 
        }

        float t=clock.restart().asSeconds();
        timer+=t;

        if(timer>delay){
            _u.update(_w);
            timer-=delay;
        }
        float alpha=timer/delay;

        //-------------------------------
        window.clear();

        for(auto& i: enemies){
            i.draw(window, _w, alpha);
        }

        _w.draw(window);
        _u.draw(window, alpha);

        window.display();
        //-------------------------------
    }
}

int main(){
    execute();
    return 0;
}

//g++ -o m main.cpp -lsfml-graphics -lsfml-window -lsfml-system
